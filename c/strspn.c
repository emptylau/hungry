#include <string.h>


int main(){

    const char* str = "Linux war first developed for 386/486-based pcs.";

    printf("%d\n", strspn(str, "Linux"));
    printf("%d\n", strspn(str, "/-"));
    printf("%d\n", strspn(str, "1234567890"));

    return 0;
}
