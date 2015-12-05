 /**********************************************************************
 # File Name:   calloc_p.c
 # Version:     1.0
 # Mail:        jchenglau@sina.cn
 # Created Time: 2015-12-05	
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int* pData = calloc(10, sizeof(int));
	if (0 == pData){
		printf("calloc error!\n");
		return -1;
	}

	for (int index = 0; index < 10; ++index){
		printf("%d ", pData[index]);
	}
	printf("\n");
    return 0;
}

