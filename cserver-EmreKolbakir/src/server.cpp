#include "server.h"
#include <sys/socket.h>     // For creating and managing sockets
#include <netinet/in.h>     // For internet domain addresses
#include <unistd.h>         // For POSIX operations like read() and close()
#include <iostream>         // For standard input-output stream operations
#include <fstream>          // For file stream operations
#include <sstream>          // For string stream operations
#include <arpa/inet.h>      // For IP manipulation

// Parses the HTTP request to determine the file being requested
std::string handle_request(const std::string& request) {
    std::istringstream sstream(request); // Convert string to a stream for easier parsing
    std::string method;                  // To store the HTTP method
    std::string path;                    // To store the requested path

    // Extract method and path from the request
    sstream >> method >> path;

    // Determine the file path based on the request path
    if (path == "/" || path == "/index.html") {
        return "../site/index.html";
    } else if (path == "/style.css") {
        return "../site/style.css";
    } else if (path == "/script.js") {
        return "../site/script.js";
    }
    return ""; // Return empty string if path not recognized
}

// Retrieves the content of the requested file
std::string get_content(const std::string& filepath) {
    std::ifstream file(filepath);  // Open the file with given path
    if (file) {
        // Read and return the file content if it exists
        return std::string(std::istreambuf_iterator<char>(file),
                           std::istreambuf_iterator<char>());
    } else {
        // Return a default message if file is not found
        return "File not found.";
    }
}

// Sends the response to the client
void send_response(int client_socket, const std::string& filepath) {
    // Initialize the HTTP response
    std::string response = "HTTP/1.1 200 OK\r\n";
    std::string content = get_content(filepath); // Retrieve the file content

    // Set the Content-Type header based on the file type
    if (filepath == "../site/style.css") {
        response += "Content-Type: text/css; charset=utf-8\r\n";
    } else {
        response += "Content-Type: text/html; charset=utf-8\r\n";
    }

    // Append the Content-Length header and the file content to the response
    response += "Content-Length: " + std::to_string(content.size()) + "\r\n\r\n";
    response += content;

    // Send the response to the client
    send(client_socket, response.c_str(), response.size(), 0);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr;  // Structure to hold server's address information
    char buffer[2048] = {0};         // Buffer to store client requests

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    server_addr.sin_family = AF_INET;                 // Address family is IP version 4
    server_addr.sin_port = htons(8080);               // Set port number (8080) after converting to network byte order
    inet_pton(AF_INET, "10.200.102.34", &server_addr.sin_addr); // Convert IP address from string to binary

    // Bind the socket to the specified address and port
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Start listening for client connections with a backlog of 5
    listen(server_socket, 5);

    std::cout << "Server listening on port 8080..." << std::endl;

    // Keep the server running indefinitely
    while (true) {
        // Accept a client connection
        client_socket = accept(server_socket, NULL, NULL);

        // Read the client's request into the buffer
        read(client_socket, buffer, sizeof(buffer));

        // Handle the request to get the file path
        std::string filepath = handle_request(buffer);
        // Send the appropriate response to the client
        send_response(client_socket, filepath);

        // Close the client connection
        close(client_socket);
    }

    return 0;
}