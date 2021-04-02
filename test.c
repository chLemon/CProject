#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char a = ' ';
    if (a)
    {
        printf("fu");
    }
    
    printf("%d", isblank(a));
}