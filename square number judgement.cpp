int isSquareNumber(int x)
{
    int m = (int)sqrt(x);
    if (m * m != x)
        return 0;
    return 1;
}
