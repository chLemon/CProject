#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct test{
    int a;
    int b;
} test1;


int main(int argc, char const *argv[])
{
    char a = ' ';
    if (a)
    {
        printf("fu");
    }
    struct test test2;
    
    printf("%d", isblank(a));
}