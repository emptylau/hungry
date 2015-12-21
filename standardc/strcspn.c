#include <string.h>


int main(){

    const char* str = "Linux war first developed for 386/486-based pcs. ";
    printf("%d\n", (int)strcspn(str, " "));
    printf("%d\n", (int)strcspn(str, "/-"));
    printf("%d\n", (int)strcspn(str, "123456790"));

    return 0;
}



