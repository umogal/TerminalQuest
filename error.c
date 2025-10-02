#include<stdio.h>

// errors.h
typedef enum {
    ERR_OK = 0,       // success
    ERR_INVALID_ARG,  // bad parameter
    ERR_IO,           // file/network error
    ERR_TIMEOUT,      
    ERR_UNKNOWN       
} ErrorCode;

int print_err(ErrorCode Code) {

switch (Code) {
 case ERR_OK: 
     fprintf(stderr, "No error"\n)
break; 
        case ERR_INVALID_ARG: 
              return "Invalid argument";
        case ERR_IO: 
        return "I/O error";
        case ERR_TIMEOUT:
        return "Timeout";
        default:
        return "Unknown error";

}

}

