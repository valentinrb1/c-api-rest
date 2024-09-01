/**
 * @file api.c
 * 
 * @brief Source file for the implementation of the API functions.
 * 
 * @author  Robledo, Valentín
 * @date    June 2023
 * @version 1.0
*/

#include "../inc/api.h"

int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    struct _u_instance instance;

    if(ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
    {
        printf("Error creating ulfius instance.\nError: %s\n", strerror(errno));
        
        exit(EXIT_FAILURE);
    }

    ulfius_add_endpoint_by_val(&instance, "POST", "/increment", NULL, 0, &increment, NULL);

    ulfius_add_endpoint_by_val(&instance, "GET", "/print", NULL, 0, &print_counter, NULL);

    if(ulfius_start_framework(&instance) == U_OK)
    {
        printf("Server started.\n");

        getchar();
    }
    else
    {
        printf("Error starting server.\nError: %s\n", strerror(errno));

        exit(EXIT_FAILURE);
    }

    ulfius_stop_framework(&instance);
    ulfius_clean_instance(&instance);

    return EXIT_SUCCESS;
}

int increment(const struct _u_request* request, struct _u_response* response, void* user_data)
{
    printf("Request POST received.\n");

    UNUSED(request);
    UNUSED(response);
    UNUSED(user_data);
    
    counter++;

    return U_CALLBACK_CONTINUE;
}

int print_counter(const struct _u_request* request, struct _u_response* response, void* user_data)
{
    printf("Request GET received.\n");

    UNUSED(request);
    UNUSED(user_data);

    char* str_counter = calloc(10, sizeof(char));
    
    sprintf(str_counter, "%d\n", counter); 
    
    str_counter[strlen(str_counter)] = '\0';

    ulfius_set_string_body_response(response, 200, str_counter);

    free(str_counter);

    return U_CALLBACK_CONTINUE;
}