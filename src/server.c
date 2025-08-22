/*
    server.c — Basic HTTP Server (Skeleton for Person A)

    Person A focuses ONLY on:
    - setting up sockets
    - accepting client connections
    - receiving raw HTTP requests
    - calling Person B’s parser
    - sending back a response
*/

#include <stdio.h>
#include<sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include "http.h"

int main(int argc, char *argv[]) {
    // 1. Parse command-line argument for port number
    if(argc>1){
        int port_number = atoi(argv[1]);
        //printf("%d\n",port_number);
    }else{
        printf("The port number is not specified\n");
    }
    // 2. Create a TCP socket
    int server_socket = socket(AF_INET,SOCK_STREAM,0);
    if(server_socket==-1){
        perror("Error creating socket");
        return 0;
    }
    // 3. Configure server address (IPv4, INADDR_ANY, port)
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);
    // 4. Bind socket to the port
    bind(server_socket, (struct sockaddr*)&server_addr,sizeof(server_addr));
    // 5. Mark socket as passive with listen()

    // 6. Main server loop
    //while (1) {
        // 6a. Accept a client connection (new socket)

        // 6b. Receive raw HTTP request into a buffer

        // 6c. Call Person B’s parser:
        //     struct http_request req = parse_http_request(buffer);

        // 6d. Based on req.path or req.method, decide what to return
        //     (for now, always send "Hello, World!" as plain text)

        // 6e. Send HTTP response to client

        // 6f. Close client socket
        //     free_http_request(&req);   // clean up memory allocated by parser
    //}

    // 7. Close the server socket (if loop ends)
    return 0;
}
