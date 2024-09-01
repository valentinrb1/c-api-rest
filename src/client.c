/**
 * @file clients.c
 * 
 * @brief Source file for the implementation of the client functions.
 *
 * @details Contains the main function and the functions used by the client.
 * 
 * @author Robledo, Valentín 
 * @date June 2023
 * @version 1.0
 * 
 * @copyright Copyright (c) 2023
 */

#include "../inc/client.h"

int main(int argc, char* argv[]) 
{   
    (void)argv;

    if(argc != 1)
    {
        printf("Error: invalid arguments.");
        exit(EXIT_FAILURE);
    }

    if(connect_ipv4_sockect(IP, SOCKET_PORT_IPV4) == -1)
        exit(EXIT_FAILURE);
    
    set_request(client_socket);

    return 0;
}

void set_request(int client_socket)
{
    FILE* file = stdin;
    u_int8_t read_flag;

    while(1){   
        char *command;
        char *buffer = malloc(100);

        do
        {
            command = malloc(100);               
            read_flag = read_input(file, command);

            if(read_flag == INPUT_OMIT)
                free(command);
        }while(read_flag == INPUT_OMIT);

        if(!strcmp(command, "POST"))
            set_post_request(buffer);
        else if(!strcmp(command, "GET"))
            set_get_request(buffer);
        else
            printf("Invalid command.\n");

        api_request(client_socket, command, buffer);

        free(command);
        free(buffer);
    }
}

void api_request(int client_socket, char* command, char* buffer)
{
    char* response = calloc(100, sizeof(char));
    memset(response, 0, 100);

    if(send(client_socket, buffer, strlen(buffer), 0) == -1)
    {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }

    if(recv(client_socket, response, 100, 0) == -1)
    {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    
    if(!strcmp(command, "POST"))
        printf("Counter incremented.\n");
    else
        print_cut_string(response);

    free(response);
}

void print_cut_string(char* buffer)
{
    char* last_rn = strrchr(buffer, '\r');
    
    char* result = calloc(100, sizeof(char));
    
    if(last_rn != NULL) {
        strcpy(result, last_rn + 2);
    }

    printf("%s", result);

    free(result);
}

void set_post_request(char* buffer)
{
    sprintf(buffer, "POST /increment HTTP/1.1\r\n");
    sprintf(buffer + strlen(buffer), "Host: %s\r\n", IP);
    sprintf(buffer + strlen(buffer), "Content-Length: 0\r\n");
    sprintf(buffer + strlen(buffer), "\r\n");
}

void set_get_request(char* buffer)
{
    sprintf(buffer, "GET /print HTTP/1.1\r\n");
    sprintf(buffer + strlen(buffer), "Host: %s\r\n", IP);
    sprintf(buffer + strlen(buffer), "\r\n");
}

int connect_ipv4_sockect(const char *socket_ipv4, const uint16_t socket_port)
{
    struct sockaddr_in server_address;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0)
    {
        perror("socket() failed");
        return -1;
    } 

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(socket_port);

    if(inet_pton(AF_INET, socket_ipv4, &server_address.sin_addr) <= 0) 
    {
        perror("socket() failed");
        return -1;
    }

    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        perror("connect() failed");
        return -1;
    }

    printf("Connected to server.\n");

    return 0;
}

u_int8_t read_input(FILE* file, char* line)
{
    char* result = fgets(line, 100, file);                                                                   
    if(result == NULL || *line == '\n' || *line == ' ')
        return INPUT_OMIT;
    
    if(line[strlen(line) - 1] != '\n')
        line[strlen(line)] = '\0';
    else
        line[strlen(line) - 1] = '\0';
    
    for(size_t i = 0; i <= strlen(line) - 1; i++)
        if(line[i] == '\t') 
            line[i] = ' '; 

    return INPUT_OK;
}