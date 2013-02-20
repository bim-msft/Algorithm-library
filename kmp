//PID: hdu 1358
//Link: http://acm.hdu.edu.cn/showproblem.php?pid=1358
//Algorithm: Use KMP to calculate recurring period of a given string

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000100;
const int maxm = 1000100;

int P[maxm];
char A[maxn], B[maxm];

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
            return i - m + 2;
    }
    return -1;
}

void printa(int* ptr, int offset)
{
    for (int i = 0; i < offset; i++)
        printf("%d ", *(ptr + i));
    putchar('\n');
}

int main()
{
    int m, cases = 0;
    while (scanf("%d", &m) > 0 && m)
    {
        scanf("%s", B);
        preprocess(B, P, m);

        printf("Test case #%d\n", ++cases);
        for (int i = 2; i <= m; i++)
        {
            if (P[i - 1] != -1 && i % (i - P[i - 1] - 1) == 0)
                printf("%d %d\n", i, i / (i - P[i - 1] - 1));
        }
        printf("\n");
    }

    return 0;
}


//PID: hdu 1711
//Link: http://acm.hdu.edu.cn/showproblem.php?pid=1711
//Algorithm: Typical KMP usage

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000100;
const int maxm = 10100;

int P[maxm];
int A[maxn], B[maxm];

int n, m;

void preprocess(int* B, int* P, int m = -1)
{
    P[0] = -1;
    int j = -1;

    //if (m == -1)
        //m = strlen(B);

    for (int i = 1; i < m; i++)
    {
        while (j != -1 && B[j + 1] != B[i])
            j = P[j];

        if (B[j + 1] == B[i])
            j++;
        P[i] = j;
    }
}

int kmp(int* A, int* B, int* P, int n = -1, int m = -1)
{
    int j = -1;

    //if (n == -1)
        //n = strlen(A);
    //if (m == -1)
        //m = strlen(B);

    for (int i = 0; i < n; i++)
    {
        while (j != -1 && B[j + 1] != A[i])
            j = P[j];

        if (B[j + 1] == A[i])
            j++;
        if (j == m - 1)
            return i - m + 2;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        for (int i = 0; i < m; i++)
            scanf("%d", &B[i]);

        preprocess(B, P, m);

        printf("%d\n", kmp(A, B, P, n, m));
    }

    return 0;
}

