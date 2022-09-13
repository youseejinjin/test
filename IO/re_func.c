#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int(*func(int a)) (int, int)
{
    if (a == 1) {
        return add;
    }

    return sub;
}

/* 定义函数指针类型 */
typedef int (* func_t)(int, int);

int main(int argc, const char *argv[])
{
    int k;
    func_t p1;
    int (*p2)(int, int);

    p1 = func(1);
    p2 = func(2);
    k = p1(1, 3);
    printf("k = %d\n", k);

    k = p2(1, 3);
    printf("k = %d\n", k);

    return 0;
}
