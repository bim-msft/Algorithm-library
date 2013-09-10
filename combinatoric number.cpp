int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int calcFact(int x)
{
    int ans = 1;
    for (int i = 2; i <= x; i++)
        ans *= i;
    return ans;
}

int calcCombinatoric(int n, int r)
{
    int ans = 1;
    int down = calcFact(r);
    for (int i = n; i > n - r; i--)
    {
        ans *= i;
        int g = gcd(ans, down);
        ans /= g;
        down /= g;
    }
    return ans;
}
