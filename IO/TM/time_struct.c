#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    time_t sec;
    char *p_str = NULL;

    time(&sec);
    p_str = ctime(&sec);
    if (p_str == NULL) {
        return 0;
    }

    printf("%s\n", p_str);

    return 0;
}
