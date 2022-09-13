#include "stdio.h"
int main(void)
{
	FILE *fp = fopen("test.txt", "r+");
	if(fp==NULL)
	{
		perror("fopen");
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	fputc('p', fp);
	printf("length is %ld\n",ftell(fp));
	return 0;
}

