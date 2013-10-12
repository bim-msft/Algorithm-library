// Conditions: 0 <= arr[i] < size, 0 <= i < size

#include <stdio.h>

using namespace std;

int DuplicateNumber(int *arr, unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == -1)
            continue;
        if (arr[arr[i]] == -1)
            return arr[i];
        while (arr[arr[i]] != -1)
        {
            int x = arr[arr[i]];
            arr[arr[i]] = -1;
            arr[i] = x;

            if (arr[arr[i]] == -1)
            {
                return arr[i];
            }
            if (i == arr[i])
            {
                arr[i] = -1;
                break;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    int arr[1024];
    while (scanf("%d", &n) > 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", DuplicateNumber(arr, n));
    }
    return 0;
}
