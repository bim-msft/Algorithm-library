// About the algorithm : http://uranux.com/res/algorithm/扩展KMP算法.ppt

const int maxn = 1100100;

char A[maxn];
char B[maxn];
int P[maxn];
int EX[maxn];

void ex_preprocess(char* B, int* P, int m = -1)
{
    int a = 0, p, L;

    if (m == -1)
        m = strlen(B);

    P[0] = m;
    while (a + 1 < m && B[a] == B[a + 1])
        a++;
    P[1] = a;
    a = 1;

    for (int k = 2; k < m; k++)
    {
        p = a + P[a] - 1;
        L = P[k - a];

        if (k + L - 1 >= p)
        {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;

            while (k + j < m && B[j] == B[k + j])
                j++;
            P[k] = j;
            a = k;
        }
        else
            P[k] = L;
    }
}

void ex_kmp(char* A, char* B, int* P, int* EX, int n = -1, int m = -1)
{
    int a = 0, p, L;

    if (n == -1)
        n = strlen(A);
    if (m == -1)
        m = strlen(B);

    while (a < m && B[a] == A[a])
        a++;
    EX[0] = a;
    a = 0;

    for (int k = 1; k < n; k++)
    {
        p = a + EX[a] - 1;
        L = P[k - a];

        if (k + L - 1 >= p)
        {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;

            while (k + j < n && B[j] == A[k + j])
                j++;
            EX[k] = j;
            a = k;
        }
        else
            EX[k] = L;
    }
}


// PID: pku 3974
// Link: http://poj.org/problem?id=3974
// Algorithm: Use extend-kmp to calculate the length of the largest palindromic sub-string.
// Note: The string length may reach 1 million ! And the time limit is 15000ms, that means only O(n) and O(nlogn) are allowed.
// Tips: It's O(nlogn). 
         Emm.. the code still can't get an Accepted, but it works well on about 200MB random data.
         I'm trying to find the reason... 
         If you clever boy see it, please mail to michaelalan@yeah.net or reply http://poj.org/showmessage?message_id=180052, really appreciate !

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1100100;

char A[maxn];
int ex_west[maxn] = {0};
int ex_east[maxn] = {0};
int P[maxn];
char L[maxn >> 1], R[maxn >> 1];
char rev_L[maxn >> 1], rev_R[maxn >> 1];

int cnt_max_len = 0;

void ex_preprocess(char* B, int* P, int m = -1)
{
    int a = 0, p, L;

    if (m == -1)
        m = strlen(B);

    P[0] = m;
    while (a + 1 < m && B[a] == B[a + 1])
        a++;
    P[1] = a;
    a = 1;

    for (int k = 2; k < m; k++)
    {
        p = a + P[a] - 1;
        L = P[k - a];

        if (k + L - 1 >= p)
        {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;

            while (k + j < m && B[j] == B[k + j])
                j++;
            P[k] = j;
            a = k;
        }
        else
            P[k] = L;
    }
}

void ex_kmp(char* A, char* B, int* P, int* EX, int n = -1, int m = -1)
{
    int a = 0, p, L;

    if (n == -1)
        n = strlen(A);
    if (m == -1)
        m = strlen(B);

    while (a < m && B[a] == A[a])
        a++;
    EX[0] = a;
    a = 0;

    for (int k = 1; k < n; k++)
    {
        p = a + EX[a] - 1;
        L = P[k - a];

        if (k + L - 1 >= p)
        {
            int j = (p - k + 1) > 0 ? (p - k + 1) : 0;

            while (k + j < n && B[j] == A[k + j])
                j++;
            EX[k] = j;
            a = k;
        }
        else
            EX[k] = L;
    }
}

void string_rev(char* S, char* rev_S, int n = -1)
{
    if (n == -1)
        n = strlen(S);

    for (int i = 0; i < n; i++)
        rev_S[n - i - 1] = S[i];
    rev_S[n] = '\0';
}

int is_valid(char* S, int n = -1)
{
    if (n == -1)
        n = strlen(S);

    int mid = n >> 1;
    for (int i = 0; i < mid; i++)
    {
        if (S[i] != S[n - i - 1])
            return 0;
    }
    return 1;
}

void int_array_rev(int* A, int n)
{
    int mid = n >> 1;
    for (int i = 0; i < mid; i++)
    {
        int tmp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = tmp;
    }
}

int solve(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (r - l + 1 <= cnt_max_len)
        return 1;

    int mid = (l + r) >> 1;
    int len = r - l + 1;
    int L_len = mid - l + 1;
    int R_len = len - L_len;

    int ret = 1;
    int cnt = 1;

    while (mid - cnt >= l)
    {
        if (A[mid - cnt] == A[mid])
            cnt++;
        else
            break;
    }
    ret += cnt - 1;
    int l_pos = mid - (cnt - 1);

    cnt = 1;
    while (mid + cnt <= r)
    {
        if (A[mid + cnt] == A[mid])
            cnt++;
        else
            break;
    }
    ret += cnt - 1;
    int r_pos = mid + (cnt - 1);

    cnt = 1;
    while (l_pos - cnt >= l && r_pos + cnt <= r)
    {
        if (A[l_pos - cnt] == A[r_pos + cnt])
            cnt++;
        else
            break;
    }
    ret += (cnt - 1) << 1;

    memcpy(L, A + l, sizeof(char) * L_len);
    L[L_len] = '\0';
    string_rev(L, rev_L, L_len);

    memcpy(R, A + mid + 1, sizeof(char) * R_len);
    R[R_len] = '\0';
    string_rev(R, rev_R, R_len);

    for (int i = 0; i < len; i++)
        P[i] = ex_west[i] = ex_east[i] = 0;

    ex_preprocess(rev_L, P, L_len);
    ex_kmp(L, rev_L, P, ex_east, L_len, L_len);

    for (int i = 0; i < len; i++)
        P[i] = 0;

    ex_preprocess(R, P, R_len);
    ex_kmp(rev_L, R, P, ex_west, L_len, R_len);
    int_array_rev(ex_west, L_len);

    for (int k = l + 1; k <= mid; k++)
    {
        int len = 0;
        if ((ex_east[k] << 1) >= mid - k + 1)
        {
            int x = ex_east[k];
            len = (k - 1 >= l ? (ex_west[k - l - 1] << 1) : 0) + mid - k + 1;
        }
        ret = ret > len ? ret : len;
    }

    for (int i = 0; i < len; i++)
        P[i] = ex_west[i] = ex_east[i] = 0;

    ex_preprocess(rev_L, P, L_len);
    ex_kmp(R, rev_L, P, ex_east, R_len, L_len);

    for (int i = 0; i < len; i++)
        P[i] = 0;

    ex_preprocess(R, P, R_len);
    ex_kmp(rev_R, R, P, ex_west, R_len, R_len);
    int_array_rev(ex_west, R_len);

    mid++;
    for (int k = mid; k <= r; k++)
    {
        int len = 0;

        if ((ex_west[k - mid] << 1) >= k - mid + 1)
        {
            int x = ex_west[k - mid];
            len = (k + 1 <= r ? (ex_east[k - mid + 1] << 1) : 0) + k - mid + 1;
        }
        ret = ret > len ? ret : len;
    }
    int L_ret = solve(l, mid - 1);
    int R_ret = solve(mid, r);

    ret = ret > L_ret ? ret : L_ret;
    ret = ret > R_ret ? ret : R_ret;

    cnt_max_len = cnt_max_len > ret ? cnt_max_len : ret;

    return ret;
}

int main()
{
    int cases = 1;
    while (scanf("%s", A) > 0 && strcmp(A, "END"))
    {
        int n = strlen(A);
        cnt_max_len = 1;

        printf("Case %d: ", cases++);
        if (is_valid(A, n))
            printf("%d\n", n);
        else
            printf("%d\n", solve(0, n - 1));
    }

    return 0;
}
