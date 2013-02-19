// p is the prime table, pIndex is its length

int calcDivisorCount(int x)
{
    int retVal = 1;
    for (int i = 0; i < pIndex && p[i] <= x; i++)
    {
        int count = 0;
        while (!(x % p[i]))
        {
            x /= p[i];
            count++;
        }
        retVal *= count + 1;
    }
    return retVal;
}
