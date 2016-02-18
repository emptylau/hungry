#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int ret = mkdir("/home/ljc/opt/hzy", S_IRWXU | S_IROTH | S_IXOTH);
    if (0 != ret){
        printf("create dir error\n");
    }

    return 0;
}
