#include <cstdio>
#include <cstring>

using namespace std;

int P[200020];
char str[200020];

int _Min(int a, int b)
{
    int _a = a;
    int _b = b;
    return _a < _b ? _a : _b;
}

int Manacher(char* str, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        str[(i + 1) << 1] = str[i];
        str[((i + 1) << 1) + 1] = '#';
    }
    str[0] = '$';
    str[1] = '#';

    int mx = 0;
    int id = 1;
    int retVal = 1;
    n <<= 1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (mx > i)
            P[i] = _Min(P[(id << 1) - i], mx - i);
        else
            P[i] = 1;

        while (str[i + P[i]] == str[i - P[i]] && i + P[i] <= n + 1 && i - P[i] >= 1)
            P[i]++;

        if (i + P[i] > mx)
        {
            mx = i + P[i];
            id = i;
        }
        retVal = retVal > P[i] - 1 ? retVal : P[i] - 1;
    }
    return retVal;
}

int main()
{
    while (scanf("%s", str) > 0)
        printf("%d\n", Manacher(str, strlen(str)));
    return 0;
}
