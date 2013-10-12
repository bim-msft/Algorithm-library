// Longest no-repeat substring

#include <stdio.h>
#include <string.h>

using namespace std;

int LNRS(char* str, unsigned int len)
{
    int vis[256];
    int cntLen = 1;
    int cntStart = 0;
    int retVal = 1;
    int retStart = 0;
    memset(vis, -1, sizeof(vis));

    vis[str[0]] = 0;
    for (int i = 1; i < len; i++)
    {
        if (vis[str[i]] == -1)
        {
            cntLen++;
            vis[str[i]] = i;
        }
        else
        {
            if (cntStart <= vis[str[i]])
            {
                cntLen = i - vis[str[i]];
                cntStart = vis[str[i]] + 1;
                vis[str[i]] = i;
            }
            else
            {
                cntLen++;
                vis[str[i]] = i;
            }
        }
        if (retVal < cntLen)
        {
            retVal = cntLen;
            retStart = cntStart;
        }
    }
    for (int i = 0; i < retVal; i++)
    {
        putchar(str[retStart + i]);
    }
    putchar('\n');

    return retVal;
}

int main()
{
    char str[1024];
    while (scanf("%s", str) > 0)
    {
        LNRS(str, strlen(str));
    }
    return 0;
}
