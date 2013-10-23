#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
bool QuickSortDefaultCmp(T* p1, T* p2)
{
	return *p1 < *p2;
}

template<typename T>
void Swap(T* p1, T* p2)
{
	T tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*
617531443 -
-17531443 6
31753144- 6
31-531447 6
3145314-7 6
314531467 -
*/
template<typename T>
void QuickSort(T* arr, int l, int r, bool (*cmp)(T*, T*) = QuickSortDefaultCmp)
{
	if (l >= r)
		return;
	if (r == l + 1)
	{
		if (!cmp(arr + l, arr + r))
			Swap(arr + l, arr + r);
		return;
	}
	int pivot = l;
	int hole = l;
	T pivotVal = arr[pivot];
	int i = l;
	int j = r;
	while (i < j)
	{
		while (j > i)
		{
			if (cmp(arr + j, &pivotVal))
			{
				arr[hole] = arr[j];
				hole = j;
				break;
			}
			j--;
		}
		while (i < j)
		{
			if (!cmp(arr + i, &pivotVal))
			{
				arr[hole] = arr[i];
				hole = i;
				break;
			}
			i++;
		}
	}
	arr[hole] = pivotVal;
	QuickSort(arr, l, hole - 1, cmp);
	QuickSort(arr, hole + 1, r, cmp);
}

bool Decreasing(char* a, char* b)
{
	return *a > *b;
}

int main()
{
	char s[] = "617531443";
	QuickSort<char>(s, 0, strlen(s) - 1);
	cout << s << endl;
	return 0;
}
