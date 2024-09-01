/**
 * @file api.h
 * 
 * @brief Header file for implementing the API functions.
 * 
 * @author Robledo, Valentín
 * @date June 2023
 * @version 1.0
 * 
 * @copyright Copyright (c) 2023
*/
#ifndef __API_H__
#define __API_H__

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ulfius.h>

/* UNUSED macro*/
#define UNUSED(x) (void)(x)

/* SERVER PORT */
#define PORT 8537

int counter;

/**
 * @brief Callback function that increments the counter.
 * 
 * @param request Pointer to the request.
 * @param response Pointer to the response.
 * @param user_data Pointer to the user data.
 *
 * @return Returns U_CALLBACK_CONTINUE.
*/
int increment(const struct _u_request* request, struct _u_response* response, void* user_data);

/**
 * @brief Callback function that prints the counter.
 *
 * @param request Pointer to the request.
 * @param response Pointer to the response.
 * @param user_data Pointer to the user data.
 *
 * @return Returns U_CALLBACK_CONTINUE.
*/
int print_counter(const struct _u_request* request, struct _u_response* response, void* user_data);

#endif // __FRAMEWORK_H__ 