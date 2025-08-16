/*
    http_parser.c — HTTP Request Parser (Skeleton for Person B)

    Person B focuses ONLY on:
    - defining the request data structure
    - parsing raw request string
    - providing helper functions for Person A to call
*/

#include <string.h>
#include "http.h"
#include <stdlib.h>



void add_header(struct http_request *req,const char *key,const char *value){
    req->header = realloc(req->header,(req->header_count+1)*sizeof(struct http_header));
    req->header[req->header_count].key = strdup(key);
    req->header[req->header_count].value = strdup(value);
    req->header_count++;
}


struct http_request parse_http_request(char *raw) {
    struct http_request request;
    char * token = strtok(raw,"\r\n");
    while(token){
        request.method = strtok(token," ");
        request.path = strtok(NULL," ");
        request.version = strtok(NULL," ");
    }
    token = strtok(NULL,"\r\n");
    while(token != NULL){
        char * colon_pos = strchr(token,':');
        if(colon_pos != NULL){
            *colon_pos = '\0';
            char *key = token;
            char *value = colon_pos+1;
            while(*value == ' ') value ++;
            add_header(&request,key,value);
        }
        token = strtok(NULL,"\r\n");
    }
    return request;
}


void free_http_request(struct http_request *req) {
    for(int i=0;i<req->header_count;i++){
        free(req->header[i].key);
        free(req->header[i].value);
    }
}

