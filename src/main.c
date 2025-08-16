#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http.h"   // include your header

// forward declarations from http_parser.c
struct http_request parse_http_request(char *raw);
void free_http_request(struct http_request *req);

int main() {
    // Example raw HTTP request
    char raw_request[] =
        "GET /index.html HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "User-Agent: TestClient/1.0\r\n"
        "Accept: text/html\r\n"
        "\r\n";

    // Parse request
    struct http_request req = parse_http_request(raw_request);

    // Print parsed request line
    printf("Method:  %s\n", req.method);
    printf("Path:    %s\n", req.path);
    printf("Version: %s\n", req.version);

    // Print headers
    printf("Headers:\n");
    for (int i = 0; i < req.header_count; i++) {
        printf("  %s: %s\n", req.header[i].key, req.header[i].value);
    }

    // Free memory
    free_http_request(&req);

    return 0;
}




