#include <stdio.h>
#include <string.h>
 
int main()
{
 
    FILE *fp = fopen("1.jpg", "r");
    FILE *fd = fopen("2.jpg", "w");
 
    while (1)
    {
        int c = fgetc(fp);    //读取
        fprintf(fd,"%c",c);    //写入
 
        if(c == EOF)        //当c不等于零时
            break;
    }
    fclose(fp);
    fclose(fd);
}
