#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 105;

int a[maxn][maxn];
int dp[maxn][maxn][maxn];

int main()
{
    int n;
    while (scanf("%d", &n) > 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                dp[i][i][k] = a[i][k];
                for (int j = i + 1; j < n; j++)
                {
                    dp[i][j][k] = dp[i][j - 1][k] + a[j][k];
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int tmpMax = 0;
                for (int k = 0; k < n; k++)
                {
                    tmpMax += dp[i][j][k];
                    if (tmpMax > ans)
                        ans = tmpMax;
                    else if (tmpMax < 0)
                        tmpMax = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
