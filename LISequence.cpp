#include <cstdio>
#include <cstring>

using namespace std;

int dp[1000];

int _Max(int a, int b)
{
    int _a = a;
    int _b = b;
    return _a > _b ? _a : _b;
}

int LIS(int* A, int n)
{
    int retVal = 1;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            dp[i] = _Max(dp[i], A[i] > A[j] ? dp[j] + 1 : 1);
        retVal = _Max(retVal, dp[i]);
    }
    return retVal;
}

int main()
{
    int A[1000];
    int n;
    while (scanf("%d", &n) > 0)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", LIS(A, n));
    }
    return 0;
}
