#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    time_t sec;
    struct tm *p_tm = NULL;

    time(&sec);
    p_tm = localtime(&sec);
    if (p_tm == NULL) {
        return 0;
    }

    printf("%d-%d-%d %d:%d:%d\n",
            p_tm->tm_year + 1900,
            p_tm->tm_mon + 1,
            p_tm->tm_mday,
            p_tm->tm_hour,
            p_tm->tm_min,
            p_tm->tm_sec);
    printf("tm_wday = %d\n", p_tm->tm_wday);
    printf("tm_yday = %d\n", p_tm->tm_yday);
    printf("tm_isdst = %d\n", p_tm->tm_isdst);

    return 0;
}
