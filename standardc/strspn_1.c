#include <string.h>
#include <stdio.h>

int main(){

    int i = 0;
    char strtext[] = "129th";
    char cset[] = "1234567890";

    i = strspn(strtext, cset);
    printf("The initial number has %d digits.\n", i);

    return 0;
}
