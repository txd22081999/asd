#include "Header.h"
int sequentialSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return 1;
		}
	}
	return -1;
}

int binarySearch(int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearch(a, l, mid - 1, x);
		return binarySearch(a, mid + 1, r, x);
	}

	return -1;
}

void sort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void listRandom(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
	int t = a[rand() % (n - 1)];
	printArray(a, n);
	cout << "Gia tri can tim : " << t << endl;
	sequentialSearch(a, n, t);
	sort(a, n);
	binarySearch(a, 0, n - 1, t);
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}