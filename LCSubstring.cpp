#include <cstdio>
#include <cstring>

int dp[2][1000];

int LCS(char* A, char* B, int n, int m)
{
    memset(dp, 0, sizeof(dp));
    int retVal = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] != B[j])
                continue;

            dp[cnt][j] = (A[i] == B[j]);

            if (i >= 1 && j >= 1)
                dp[cnt][j] += dp[(cnt + 1) & 1][j - 1];

            retVal = retVal > dp[cnt][j] ? retVal : dp[cnt][j];
        }
        cnt++;
        cnt &= 1;
    }
    return retVal;
}

int main()
{
    char A[1000], B[1000];
    while (scanf("%s%s", A, B) > 0)
    {
        int n = strlen(A);
        int m = strlen(B);
        printf("%d\n", LCS(A, B, n, m));
    }
    return 0;
}
