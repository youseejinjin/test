#include<stdio.h>
int main()
{
	char str1[]="hello world";
	char str2[]="world hello";
	char str3[1024]={0};
	FILE *stream=fopen("fprintf.out","w");
	sprintf(str3,"%s_%s",str1,str3);
	printf("%s\n",str3);
	fprintf(stream,"%s a %s",str1,str2);
	fclose(stream);
	return 1;
}
