#include <iostream>
#include <cstring>

template<typename T>
bool MergeSortDefaultCmp(T* p1, T* p2)
{
	return *p1 < *p2;
}

template<typename T>
void MergeSort(T* arr, int l, int r, bool (*cmp)(T*, T*) = MergeSortDefaultCmp)
{
	if (l >= r)
		return;
	int length = r - l + 1;
	T* sorted = new T[length];
	int middle = length >> 1;
	MergeSort(arr, l, l + middle - 1, cmp);
	MergeSort(arr, l + middle, r, cmp);
	int i = l;
	int j = l + middle;
	int k = 0;
	while (i <= l + middle - 1 && j <= r)
	{
		if (cmp(arr + i, arr + j))
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	while (i <= l + middle - 1)
		sorted[k++] = arr[i++];
	while (j <= r)
		sorted[k++] = arr[j++];
	for (i = l; i <= r; i++)
		arr[i] = sorted[i - l];
}

bool Decreasing(char* a, char* b)
{
	return *a > *b;
}

int main()
{
	char s[] = "617531443";
	MergeSort<char>(s, 0, strlen(s) - 1, Decreasing);
	std::cout << s << std::endl;
	return 0;
}
