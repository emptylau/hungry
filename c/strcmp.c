#include <stdio.h>
#include <string.h>

int main(){

    const char* key = "key_xx";
    char buffer[48] = {0};


    do {

        bzero(buffer, sizeof(buffer));

        printf("please enter a key: ");
        fflush(stdout);

        scanf("%47s", buffer);

    //}while(strcmp(buffer, key) != 0);
    //}while(strcasecmp(buffer, key) != 0);
    }while(strncasecmp(buffer, key, 4) != 0);
    printf("key is correct!\n");


    
    return 0;
}
