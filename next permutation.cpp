#include <stdio.h>
#include <string.h>

void Swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void Reserve(char *s, char *e)
{
    if (s > e)
        return;
    while (s < e)
    {
        Swap(s++, e--);
    }
}

int NextPermutation(char *str, char *end)
{
    char *replacePos = NULL;
    for (char *cntPos = end - 2; cntPos >= str; cntPos--)
    {
        if (*cntPos < *(cntPos + 1))
        {
            replacePos = cntPos;
            break;
        }
    }
    if (!replacePos)
        return 0;

    for (char *cntPos = end - 1; cntPos > replacePos; cntPos--)
    {
        if (*cntPos > *replacePos)
        {
            Swap(cntPos, replacePos);
            break;
        }
    }
    Reserve(replacePos + 1, end - 1);

    return 1;
}

int main()
{
    char str[1024];
    while (scanf("%s", &str) > 0)
    {
        unsigned int len = strlen(str);
        do
        {
            printf("%s\n", str);
        }
        while (NextPermutation(str, str + len));
    }
    return 0;
}
