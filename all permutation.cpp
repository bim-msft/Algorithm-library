#include <stdio.h>
#include <string.h>

void Swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void AllPermutation(char *str, int k, unsigned int len)
{
    if (k == len - 1)
    {
        printf("%s\n", str);
        return;
    }
    for (int i = k; i < len; i++)
    {
        int ok = 1;
        for (int j = k; j < i; j++)
        {
            if (str[j] == str[i])
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
            continue;
        Swap(str + k, str + i);
        AllPermutation(str, k + 1, len);
        Swap(str + i, str + k);
    }
}

int main()
{
    char str[1024];
    while (scanf("%s", str) > 0)
    {
        AllPermutation(str, 0, strlen(str));
    }
    return 0;
}
