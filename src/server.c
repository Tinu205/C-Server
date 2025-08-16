/*
    server.c — Basic HTTP Server (Skeleton for Person A)

    Person A focuses ONLY on:
    - setting up sockets
    - accepting client connections
    - receiving raw HTTP requests
    - calling Person B’s parser
    - sending back a response
*/

#include <...>   // sockets, I/O, strings, stdio, etc.
#include "http_parser.h"   // (Person B will provide this header)

int main(int argc, char *argv[]) {
    // 1. Parse command-line argument for port number

    // 2. Create a TCP socket

    // 3. Configure server address (IPv4, INADDR_ANY, port)

    // 4. Bind socket to the port

    // 5. Mark socket as passive with listen()

    // 6. Main server loop
    while (1) {
        // 6a. Accept a client connection (new socket)

        // 6b. Receive raw HTTP request into a buffer

        // 6c. Call Person B’s parser:
        //     struct http_request req = parse_http_request(buffer);

        // 6d. Based on req.path or req.method, decide what to return
        //     (for now, always send "Hello, World!" as plain text)

        // 6e. Send HTTP response to client

        // 6f. Close client socket
        //     free_http_request(&req);   // clean up memory allocated by parser
    }

    // 7. Close the server socket (if loop ends)
    return 0;
}

