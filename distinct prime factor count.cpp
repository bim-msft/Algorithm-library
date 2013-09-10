int calcDistinctPrimeFactorCount(int x)
{
    int res = 0;
    for (int i = 0; i < pIndex && p[i] <= x; i++)
    {
        int exist = 0;
        while (!(x % p[i]))
        {
            x /= p[i];
            exist = 1;
        }
        if (exist)
            res++;
    }
    return res;
}
