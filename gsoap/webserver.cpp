#include <cstdlib>
#include <string>
#include "webserver.nsmap"
#include "soapH.h"

static bool is_running = false;

int main(int argc, char* argv[]){

    int server_port = 8080;
    std::string server_ip("0.0.0.0");
    int backlog = 10;

    if (argc >= 2){
        server_port = atoi(argv[1]);
    }

    struct soap* soap;
    soap = soap_new();
    if (!soap){
        printf("error: soap new\n");
        return 0;
    }

    int serverfd = soap_bind(soap, server_ip.c_str(), server_port, backlog);
    if (!soap_valid_socket(serverfd)){
        printf("error: ip %s , port %d\n", server_ip.c_str(), server_port);
        return 0;
    }

    printf("info: bind successfule! ip:%s port:%d\n", server_ip.c_str(), server_port);

    is_running = true;

    while(is_running){
        
        int salverfd = soap_accept(soap);
        if (!salverfd){
            continue;
        }

        struct soap* copy = soap_copy(soap);
        if (!copy){
            printf("error: soap copy. salverfd %d\n", salverfd);
            continue;
        }

        printf("info: process savler: %d\n", salverfd);

        soap_serve(copy);
        soap_end(copy);
        soap_done(copy, NULL);

        usleep(10000);
    }

    soap_end(soap);
    soap_done(soap, NULL);

    return 0;
}


int ns__add(struct soap* soap, double a, double b, double* result){

    *result = a + b;

    return 0;
}

int ns__sub(struct soap* soap, double a, double b, double* result){
    *result = a - b;
    return 0;
}

int ns__mul(struct soap* soap, double a, double b, double* result){
    *result = a * b;
    return 0;
}

int ns__div(struct soap* soap, double a, double b, double* result){
    *result = a / b;
    return 0;
}

int f__form1(struct soap* soap){
    
    return 0;
}

int f__form2(struct soap* soap, struct f__formResponse* result){

    result->result =10;
    
    return 0;

}
