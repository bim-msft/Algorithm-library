// http://acm.hdu.edu.cn/showproblem.php?pid=3183
// With index

#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 1005;
char a[maxn];
char dp[maxn][20];
int val[maxn][20];

char _Min(char a, char b)
{
    char _a = a;
    char _b = b;
    return _a < _b ? _a : _b;
}

void buildST(int n)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = a[i];
        val[i][0] = i;
    }

    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i < n; i++)
        {

            if (i + (1 << j) > n)
                break;
            dp[i][j] = _Min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
            if (dp[i][j] == dp[i][j - 1])
                val[i][j] = val[i][j - 1];
            else
                val[i][j] = val[i + (1 << j - 1)][j - 1];
        }
    }
}

int RMQ(int l, int r)
{
    int k = floor(log(r - l + 1) / log(2));
    int x = _Min(dp[l][k], dp[r - (1 << k) + 1][k]);
    if (x == dp[l][k])
        return l * 100 + k;
    return (r - (1 << k) + 1) * 100 + k;
}

int main()
{
    int x;
    while (scanf("%s%d", a, &x) > 0)
    {
        int n = strlen(a);
        buildST(n);
        int l = 0;
        int first = 1;
        for (int i = 0; i < n - x; i++)
        {
            int ret = RMQ(l, x + i);
            int index2 = ret % 100;
            int index1 = (ret - index2) / 100;
            l = val[index1][index2] + 1;
            if (first && dp[index1][index2] == '0')
                continue;
            printf("%c", dp[index1][index2]);
            first = 0;
        }
        if (first)
            printf("0");
        printf("\n");
    }
    return 0;
}
