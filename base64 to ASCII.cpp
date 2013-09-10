// About base64: http://baike.baidu.com/view/469071.htm

int decodeBase64ToASCII(int* des, char* src)
{
    int len = strlen(src);
    int desIndex = 0;
    int incNum = 0;
    int zeroBitsCount = 0;
    int bits[6];

    for (int i = 0; i < len; i++)
    {
        if (src[i] >= 'A' && src[i] <= 'Z')
            incNum = src[i] - 'A';
        else if (src[i] >= 'a' && src[i] <= 'z')
            incNum = src[i] - 'a' + 26;
        else if (src[i] >= '0' && src[i] <= '9')
            incNum = src[i] - '0' + 52;
        else if (src[i] == '+')
            incNum = 62;
        else if (src[i] == '/')
            incNum = 63;
        else if (src[i] == '=')
        {
            zeroBitsCount = len - i;
            break;
        }

        for (int j = 0; j < 6; j++)
            bits[j] = 0;
        int cntBitIndex = 5;
        while (incNum)
        {
            bits[cntBitIndex--] = incNum % 2;
            incNum >>= 1;
        }

        for (int j = 0; j < 6; j++)
            des[desIndex + j] = bits[j] + '0';
        desIndex += 6;
    }
    desIndex -= zeroBitsCount << 1;

    for (int i = 0; i < desIndex; i += 8)
    {
        int val = 0;
        for (int j = 7; j >= 0; j--)
            val += (des[i + j] - '0') * (1 << (7 - j));
        des[i / 8] = val;
    }
    return desIndex / 8;
}
