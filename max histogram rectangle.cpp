#include <stdio.h>

void PreProcess(int *L, int *R, int *H, int n)
{
    L[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int x = i;
        while (x - 1 >= 0 && H[x - 1] >= H[i])
        {
            x = L[x - 1];
        }
        L[i] = x;
    }

    R[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int x = i;
        while (x + 1 < n && H[x + 1] >= H[i])
        {
            x = R[x + 1];
        }
        R[i] = x;
    }
}

int MaxArea(int *H, int n)
{
    int LExtension[1024];
    int RExtension[1024];
    int retVal = 0;
    PreProcess(LExtension, RExtension, H, n);
    for (int i = 0; i < n; i++)
    {
        int cntAns = H[i] * (RExtension[i] - LExtension[i] + 1);
        retVal = retVal > cntAns ? retVal : cntAns;
    }
    return retVal;
}

int main()
{
    int n;
    int Histogram[1024];

    while (scanf("%d", &n) > 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &Histogram[i]);
        }
        printf("%d\n", MaxArea(Histogram, n));
    }
    return 0;
}
