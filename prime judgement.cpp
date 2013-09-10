int isPrime(int x)
{
    if (x <= 1)
        return 0;
    int m = (int)sqrt(x);
    for (int i = 2; i <= m; i++)
    {
        if (!(x % i))
            return 0;
    }
    return 1;
}
