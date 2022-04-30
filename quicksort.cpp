#include <bits/stdc++.h>

using namespace std;

int partitions(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (pivot > A[i]);
        do
        {
            j--;
        } while (pivot < A[j]);

        if (i < j)
            swap(A[i], A[j]);
    }
    swap(A[l], A[j]);
    cout << "\n";
    for (int q = 0; q < 10; q++)
    {
        cout << A[q] << " ";
    }
    return j;
}

void quicksort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = partitions(A, l, h);

        quicksort(A, l, j);
        quicksort(A, j + 1, h);
    }
}

int main()
{
    int n = 10;
    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5, INT_MAX};
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    quicksort(arr, 0, n - 1);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
}