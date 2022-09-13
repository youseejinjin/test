#include <stdio.h>
#include <time.h>
#include <unistd.h>
 
//文本文件拷贝
int FileCopy(const char *src_path,const char*dest_path);
//输出日志文件
void PrintLogData(const char *path);
//获取文件大小
long SizeOfFile(const char *path);
 
int main() {
    char* src_path="./src.txt";
    char* dest_path="./dest.txt";
    char* log_path = "log.txt";
    PrintLogData(log_path);
    FileCopy(src_path,dest_path);
    printf("%ld\n", SizeOfFile(src_path));
    return 0;
}
 
int FileCopy(const char *src_path,const char*dest_path){
    //获取源文件的文件指针
    FILE *src_fd = fopen(src_path,"r");
    if(src_fd == NULL){
        perror("open src ");
        return -1;
    }
    //获取目标文件的文件指针
    FILE *dest_fd = fopen(dest_path,"w");
    if(dest_fd == NULL){
        perror("open dest ");
        return -1;
    }
 
    /*利用标准IO的字符IO，实现2个文件的字节拷贝*/
//    fputc(fgetc(src_fd),dest_fd);
//    while (!feof(src_fd)){
//        fputc(fgetc(src_fd),dest_fd);
//    }
 
    /*利用标准IO的行IO，实现2个文件的字节拷贝*/
//    char buf[1024];
//    while( fgets(buf, sizeof(buf),src_fd) != NULL){
//        fputs(buf,dest_fd);
//    }
 
    /*利用标准IO的块IO，实现2个文件的字节拷贝*/
    char buf[1024];
    unsigned long ret = 0;
    ret = fread(buf, 1,sizeof(buf),src_fd);
    while( ret != 0){
        fwrite(buf, 1,ret,dest_fd); //读到多少就写入多少
        printf("%ld\n",ret);
        ret = fread(buf, 1,sizeof(buf),src_fd);
    }
 
    fclose(src_fd);
    fclose(dest_fd);
    return 0;
}
 
void PrintLogData(const char *path){
    //追加的方式获取文件描述符
    FILE *fd = fopen(path,"a+");
    if(fd == NULL){
        perror("open ");
        return;
    }
 
    //获取行号
    int num = 0;
    char buf[1024];
    while(fgets(buf, sizeof(buf),fd) !=NULL){
        num++;
    }
    fseek(fd,0,SEEK_CUR);
 
    //往日志文件写数据
    int year,mon,day,hour,min,sec;
    while(num >= 0){
 
        //获取当前时间
        time_t now;
        struct tm *tm_now;
        time(&now);
        tm_now = localtime(&now);
 
        year = tm_now->tm_year+1900;
        mon = tm_now->tm_mon+1;
        day = tm_now->tm_mday;
        hour = tm_now->tm_hour;
        min = tm_now->tm_min;
        sec = tm_now->tm_sec;
 
        //%04 表示占4位，不足4位 在前面补0
        fprintf(fd,"%04d, %02d-%02d-%02d %02d:%02d:%02d\n"
                ,num,year, mon,day,hour,min,sec);
        fflush(fd);//强制刷出缓存
 
        fprintf(stdout,"%04d, %02d-%02d-%02d %02d:%02d:%02d\n"
                ,num,year, mon,day,hour,min,sec);
        sleep(1);
        num++;
    }
 
    fclose(fd);
}
 
long SizeOfFile(const char *path){
    long size = 0L;
 
    FILE *fd = fopen(path,"r");
    fseek(fd,0,SEEK_END);//偏移到文件末尾
    size = ftell(fd);
    fclose(fd);
 
    return size;
}
