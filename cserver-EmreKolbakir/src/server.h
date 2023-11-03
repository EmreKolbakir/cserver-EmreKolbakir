#ifndef SERVER_H
#define SERVER_H

#include <string>

// Function to parse the HTTP request and determine the file being requested
std::string handle_request(const std::string& request);

// Function to retrieve the content of the requested file
std::string get_content(const std::string& filepath);

// Function to send the response to the client
void send_response(int client_socket, const std::string& filepath);

#endif // SERVER_H
