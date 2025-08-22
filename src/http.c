#include <string.h> 
#include <stdlib.h>
#include "http.h"

void add_header(struct http_request *req, const char *key, const char *value) {
    req->header = realloc(req->header, (req->header_count + 1) * sizeof(struct http_header));
    req->header[req->header_count].key = strdup(key);
    req->header[req->header_count].value = strdup(value);
    req->header_count++;
}

struct http_request parse_http_request(char *raw) {
    struct http_request request;
    request.method = NULL;
    request.path = NULL;
    request.version = NULL;
    request.header = NULL;
    request.header_count = 0;

    // --- First line (request line) ---
    char *line = strtok(raw, "\r\n");
    if (line) {
        char *sp1 = strchr(line, ' ');
        char *sp2 = sp1 ? strchr(sp1 + 1, ' ') : NULL;

        if (sp1) {
            *sp1 = '\0';
            request.method = strdup(line);
            if (sp2) {
                *sp2 = '\0';
                request.path = strdup(sp1 + 1);
                request.version = strdup(sp2 + 1);
            }
        }
    }

    // --- Headers ---
    while ((line = strtok(NULL, "\r\n")) && line[0] != '\0') {
        char *colon_pos = strchr(line, ':');
        if (colon_pos) {
            *colon_pos = '\0';
            char *key = line;
            char *value = colon_pos + 1;

            while (*value == ' ') value++; // trim leading spaces
            add_header(&request, key, value);
        }
    }

    return request;
}

void free_http_request(struct http_request *req) {
    for (int i = 0; i < req->header_count; i++) {
        free(req->header[i].key);
        free(req->header[i].value);
    }
    free(req->header);

    free(req->method);
    free(req->path);
    free(req->version);
}
