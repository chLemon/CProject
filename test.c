#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLINE 1000

#define EOF 0

enum color{red, yellow};

int ifred(int color);

int main(int argc, char const *argv[]){
    
    int arr[MAXLINE];

    int a = ifred(red);
    int b = ifred(yellow);
    
    printf("%d \n %d", a, b);
    
    
    return 0;
}

int ifred(int color){
    if (color == red)
    {
        return 1;
    }
    return 0;

}