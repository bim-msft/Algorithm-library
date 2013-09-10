// 素数和表示
// 记忆化搜索+剪枝去重

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int p[100010];
int pIndex = 0;
map<int, vector<vector<int> > > hash;

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

void genPrimeTable(int upBound)
{
    for (int i = 2; i <= upBound; i++)
    {
        if (isPrime(i))
            p[pIndex++] = i;
    }
}

vector<vector<int> > divide(int x)
{
    vector<vector<int> > retVal;
    int count = 0;
    if (!hash[x].empty())
        return hash[x];

    int half_x = x >> 1;
    for (int i = 0; p[i] <= half_x; i++)
    {
        if (isPrime(x - p[i]))
        {
            retVal.push_back(vector<int>());
            retVal[count].push_back(p[i]);
            retVal[count].push_back(x - p[i]);
            count++;
        }
        vector<vector<int> > down = divide(x - p[i]);
        int size = down.size();
        for (int j = 0; j < size; j++)
        {
            int _size = down[j].size();
            retVal.push_back(vector<int>());
            retVal[count].push_back(p[i]);
            for (int k = 0; k < _size; k++)
                retVal[count].push_back(down[j][k]);

            int ok = 1;
            for (int k = 0; k < _size; k++)
            {
                if (retVal[count][k] > retVal[count][k + 1])
                {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
            {
                retVal.pop_back();
                continue;
            }
            count++;
        }
    }

    hash[x] = retVal;
    return retVal;
}

int main()
{
    genPrimeTable(100000);
    int n;
    vector<vector<int> > ans;
    while (scanf("%d", &n) > 0)
    {
        ans = divide(n);
        int size = ans.size();
        for (int i = 0; i < size; i++)
        {
            int _size = ans[i].size();
            printf("%d =", n);
            for (int j = 0; j < _size - 1; j++)
                printf(" %d +", ans[i][j]);
            printf(" %d\n", ans[i][_size - 1]);
        }
    }
    return 0;
}
