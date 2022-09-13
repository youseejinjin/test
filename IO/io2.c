#include "stdio.h"
int main()
{
  FILE  *fp;
  if((fp=fopen("test_io","w"))==NULL)
  	{

		perror("fopen");
		return -1;

	}  
	fputc('a',fp);
	fflush(fp);
	while(1);
        return 0;

}
