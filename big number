//Big number add ans multipy

void add(char* des, char* src)
{
    char tmp[10100];

    int lenDes = strlen(des);
    int lenSrc = strlen(src);

    int i, j;
    int c = 0;
    int tIndex = 0;
    for (i = lenDes - 1, j = lenSrc - 1; i >= 0 && j >= 0; i--, j--)
    {
        tmp[tIndex++] = des[i] + src[j] + c - '0';

        if (des[i] + src[j] + c - '0' > '9')
        {
            c = 1;
            tmp[tIndex - 1] -= 10;
        }
        else
            c = 0;
    }

    while (i >= 0)
    {
        tmp[tIndex++] = des[i] + c;

        if (des[i] + c > '9')
        {
            c = 1;
            tmp[tIndex - 1] -= 10;
        }
        else
            c = 0;

        i--;
    }

    while (j >= 0)
    {
        tmp[tIndex++] = src[j] + c;

        if (src[j] + c > '9')
        {
            c = 1;
            tmp[tIndex - 1] -= 10;
        }
        else
            c = 0;

        j--;
    }

    if (c != 0)
    {
        tmp[tIndex++] = c + '0';
        c = 0;
    }

    tmp[tIndex] = '\0';

    for (int i = 0; i < (tIndex >> 1); i++)
    {
        char t = tmp[i];
        tmp[i] = tmp[tIndex - i - 1];
        tmp[tIndex - i - 1] = t;
    }

    tmp[tIndex] = '\0';

    strcpy(des, tmp);
}

void mul(char* des, char* src)
{
    char ans[10100];
    char tmp[10100];

    memset(ans, 0, sizeof(ans));
    int lenDes = strlen(des);
    int lenSrc = strlen(src);

    int i, j;
    int c = 0;
    int tIndex = 0;
    for (j = lenSrc - 1; j >= 0; j--)
    {
        tIndex = 0;
        for (i = lenDes - 1; i >= 0; i--)
        {
            tmp[tIndex++] = (des[i] - '0') * (src[j] - '0') + c;

            if (tmp[tIndex - 1] > 9)
            {
                c = tmp[tIndex - 1] / 10;
                tmp[tIndex - 1] %= 10;

            }
            else
                c = 0;

            tmp[tIndex - 1] += '0';
        }

        if (c > 0)
        {
            tmp[tIndex++] = c + '0';
            c = 0;
        }

        for (int k = 0; k < (tIndex >> 1); k++)
        {
            char t = tmp[k];
            tmp[k] = tmp[tIndex - k - 1];
            tmp[tIndex - k - 1] = t;
        }

        for (int k = 0; k <= lenSrc - 1 - j; k++)
            tmp[k + tIndex] = '0';

        tIndex += lenSrc - 1 - j;
        tmp[tIndex] = '\0';

        add(ans, tmp);
    }
    strcpy(des, ans);
}
