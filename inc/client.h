/**
 * @file clients.h
 * 
 * @brief Header file corresponding to the client.c source file.
 * 
 * @author Robledo, Valentín
 * @date June 2023
 * @version 1.0
 * 
 * @copyright Copyright (c) 2023
 */
#ifndef __CLIENTS_H__
#define __CLIENTS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>

/* Keyboard input was successful */
#define INPUT_OK    0

/* Keyboard input is skipped */
#define INPUT_OMIT  1

/* CLIENT IP */
#define IP "127.0.0.1"

/* CLIENT PORT*/
#define SOCKET_PORT_IPV4 8537

int client_socket;
struct sockaddr_un server_address;

/** 
 * @brief Function that creates an IPv4 socket.
 *
 * @param socket_ipv4 IPv4 address of the socket.
 * @param socket_port Port of the socket.
 *
 * @return Returns if the connection failed.
*/
int connect_ipv4_sockect(const char *socket_ipv4, const uint16_t socket_port);

/**
 * @brief Function that is responsible for setting the request.
 *
 * Waits for keyboard input from the user and then selects
 * which request to set.
 *
 * @param client_socket File descriptor (fd) of the client socket.
 *
 * @return void
*/
void set_request(int client_socket);

/**
 * @brief Function responsible for sending the request and receiving the response from the server.
 *
 * @param client_socket File descriptor (fd) of the client socket.
 * @param command Command entered by the user.
 * @param buffer Buffer where the request will be written.
 *
 * @return void
*/
void api_request(int client_socket, char* command, char* buffer);

/**
 * @brief Function that prints the server's response.
 *
 * @param buffer Buffer where the response will be written.
*/
void print_cut_string(char* buffer);

/**
 * @brief Function that sets the POST request.
 *
 * @param buffer Buffer where the request will be written.
*/
void set_post_request(char* buffer);

/**
 * @brief Function that sets the GET request.
 *
 * @param buffer Buffer where the request will be written.
*/
void set_get_request(char* buffer);

/**
 * @brief Function that reads keyboard input.
 *
 * Prints a message on the screen indicating whether the disconnection was by the client or
 * the server.
 *
 * @param file Name of the file to read.
 * @param line Buffer where the entered line will be written.
 *
 * @return Returns INPUT_OK if the keyboard input was successful, INPUT_OMIT if the keyboard input was omitted.
*/
uint8_t read_input(FILE* file, char* line);

#endif // __CLIENTS_H__