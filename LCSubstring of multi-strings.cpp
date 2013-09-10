// PID: poj 3450
// Link: http://poj.org/problem?id=3450
// Algorithm: KMP + enumeration (brute force)

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 205;
const int maxm = 205;

int P[maxm];
char A[maxn], B[maxm];
char S[4010][maxn];

int n, m;

void preprocess(char* B, int* P, int m = -1)
{
    P[0] = -1;
    int j = -1;

    if (m == -1)
        m = strlen(B);

    for (int i = 1; i < m; i++)
    {
        while (j != -1 && B[j + 1] != B[i])
            j = P[j];

        if (B[j + 1] == B[i])
            j++;
        P[i] = j;
    }
}

int kmp(char* A, char* B, int* P, int n = -1, int m = -1)
{
    int j = -1;

    if (n == -1)
        n = strlen(A);
    if (m == -1)
        m = strlen(B);

    for (int i = 0; i < n; i++)
    {
        while (j != -1 && B[j + 1] != A[i])
            j = P[j];

        if (B[j + 1] == A[i])
            j++;
        if (j == m - 1)
            return 1;
    }
    return 0;
}

int main()
{
    int x, ansLen, ok;
    char ans[205];

    while (scanf("%d", &x) > 0 && x)
    {
        int len = 204;

        for (int i = 0; i < x; i++)
        {
            scanf("%s", S[i]);
            int tmpLen = strlen(S[i]);
            len = len < tmpLen ? len : tmpLen;
        }

        ansLen = 0;
        ok = 0;
        ans[0] = 'z' + 1;
        ans[1] = '\0';

        for (int i = len; i >= 1 && !ok; i--)
        {
            for (int j = 0; j <= len - i; j++)
            {
                char tmp[205];
                int tIndex = 0;
                for (int k = j; k < j + i; k++)
                    tmp[tIndex++] = S[0][k];
                tmp[tIndex] = '\0';
                strcpy(B, tmp);

                preprocess(B, P);

                int y;
                for (y = 1; y < x; y++)
                {
                    if (!kmp(S[y], B, P))
                        break;
                }

                if (y == x)
                {
                    ok = 1;
                    if (ansLen > i)
                        break;

                    if (strcmp(B, ans) < 0)
                        strcpy(ans, B);

                    ansLen = i;
                }
            }
        }

        printf("%s\n", ok ? ans : "IDENTITY LOST");
    }

    return 0;
}
