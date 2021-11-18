#ifndef REQUEST_H

#define REQUEST_H

#include <stddef.h>

#include "header.h"

typedef enum Method {
    METHOD_GET,
    METHOD_HEAD,
    METHOD_POST,
    METHOD_PUT,
    METHOD_DELETE,
    METHOD_CONNECT,
    METHOD_OPTIONS,
    METHOD_TRACE,
    METHOD_PATCH,
    METHOD_INVALID
} Method;

typedef struct Request {
    char *method;
    char *uri;
    char *protocol;
    Header **headers;
    size_t headers_size;
} Request;

Request request_parse(const char *raw_request);
void request_dealloc(Request *request);

#endif /* REQUEST_H */

