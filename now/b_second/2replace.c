#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *replace(char line[], char res[], char src[], char tar[])
{
    int i, j, k = 0, f;
    for (i = 0, f = 1; i < strlen(line); i++, f = 1)
    {
        for (j = 0; j < strlen(src); j++)
            if (line[i + j] != src[j])
            {
                f = 0;
                break;
            }

        if (f)
        {
            strcpy(res + k, tar);
            k += strlen(tar);
            i += strlen(src) - 1;
        }
        else
            res[k++] = line[i];
    }
    res[k] = '\0';
    return res;
}

int main(int argc, char const *argv[])
{
    FILE *in, *out;
    in = fopen("filein.txt", "r");
    out = fopen("fileout.txt", "w");
    char src[200];
    char tar[200];
    scanf("%s", src);
    scanf("%s", tar);

    char line[205];
    char *res = (char *)malloc(sizeof(char) * 205);

    while (fgets(line, 200, in) != NULL)
    {
        printf("%s\n", line);
        res = replace(line, res, src, tar);
        fputs(res, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}