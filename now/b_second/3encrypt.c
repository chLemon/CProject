#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char key[55];
    char table[26];
    int tag[26] = {0}, i, tablei = 0;
    scanf("%s", key);
    for (i = 0; i < strlen(key); i++)
    {
        int k = key[i] - 'a'; //在tag上对应的下标
        if (tag[k] == 0)
        { //表示还没出现过
            table[tablei++] = key[i];
            tag[k] = 1;
        }
    }
    for (i = 25; i >= 0; i--)
        if (tag[i] == 0)
            table[tablei++] = i + 'a';
    /* 至此密码表已经全部生成好了 */
    FILE *in, *out;
    in = fopen("encrypt.txt", "r");
    out = fopen("output.txt", "w");
    char line[205];
    while (fgets(line, 205, in) != NULL)
    {
        for (i = 0; i < strlen(line); i++)
            if (islower(line[i]))
                line[i] = table[line[i] - 'a'];
        fputs(line, out);
    }
    fclose(in);
    fclose(out);

    return 0;
}