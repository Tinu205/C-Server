#ifndef HTTP_H
#define HTTP_H

struct http_header{
    char *key;
    char *value;
};

struct http_request{
    char *method;
    char *path;
    char *version;
    struct http_header *header;
    int header_count;
};

void add_header(struct http_request *req, const char *key, const char *value);
struct http_request parse_http_request(char *raw);
void free_http_request(struct http_request *req);


#endif 

