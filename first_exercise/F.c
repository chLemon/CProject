#include <stdio.h>

int main()
{
    int number;
    scanf("%x", &number);

    if ((0x00 <= number && number <= 0x1F) || number == 0x7F)
    {
        printf("Control Character!\n");
        if (number == 0x00)
        {
            printf("Null");
        }
        else if (number == 0x09)
        {
            printf("Horizontal Tab");
        }
        else if (number == 0x0A)
        {
            printf("Line Feed");
        }
        else if (number == 0x0D)
        {
            printf("Carriage Return");
        }
        else
        {
            printf("Other Control Character");
        }
    }
    else if (number == 0x20 ||
        (0x21 <= number && number <= 0x2F) ||
             (0x3A <= number && number <= 0x40) ||
             (0x5B <= number && number <= 0x60) ||
             (0x7B <= number && number <= 0x7E))
    {
        printf("Symbol Character!\n");
        if (number == '(' || number == ')' || number == '[' || number == ']' || number == '{' || number == '}' || number == '<' || number == '>')
        {
            printf("Bracket");
        }
        else
        {
            printf("Other Symbol");
        }
    }
    else if (0x30 <= number && number <= 0x39)
    {
        printf("Digit Character!\n");
        printf("%c", number);
    }
    else if (0x41 <= number && number <= 0x5A)
    {
        printf("Upper Case Alphabet!\n");
        printf("%c", number);
    }
    else if (0x61 <= number && number <= 0x7A)
    {
        printf("Lower Case Alphabet!\n");
        printf("%c", number);
    }

    return 0;
}
