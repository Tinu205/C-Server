/*
    http_parser.c — HTTP Request Parser (Skeleton for Person B)

    Person B focuses ONLY on:
    - defining the request data structure
    - parsing raw request string
    - providing helper functions for Person A to call
*/

#include <...>   // stdio, stdlib, string functions

// 1. Define a struct to hold parsed request info
//    - method (string)
//    - path (string)
//    - version (string)
//    - headers (simple key-value array, optional at first)
//    - body (optional)

struct http_request {
    // char *method;
    // char *path;
    // char *version;
    // struct header { char *key; char *value; } headers[...];
    // char *body;
};

/*
    Function: parse_http_request
    Input: raw HTTP request string (from server.c)
    Output: filled http_request struct
*/
struct http_request parse_http_request(char *raw) {
    // 1. Split raw request into lines
    // 2. Parse request line (method, path, version)
    // 3. Parse headers (optional at first)
    // 4. Body (optional, can be empty)
    // 5. Return request struct
}

/*
    Function: free_http_request
    Purpose: Free memory allocated during parsing
*/
void free_http_request(struct http_request *req) {
    // Free all strings/arrays allocated in parse_http_request
}

