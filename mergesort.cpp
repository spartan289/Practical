#include <bits/stdc++.h>

using namespace std;

void merge(int A[], int l, int mid, int h)
{

    int m = mid - l + 1;
    int n = h - mid;
    int tmp1[m];
    int tmp2[n];
    for (int i = 0; i < m; i++)
    {
        tmp1[i] = A[l + i];
    }
    for (int i = 0; i < n; i++)
    {
        tmp2[i] = A[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < m && j < n)
    {
        if (tmp1[i] < tmp2[j])
            A[k++] = tmp1[i++];
        else
            A[k++] = tmp2[j++];
    }
    while (i < m)
        A[k++] = tmp1[i++];
    while (j < n)
        A[k++] = tmp2[j++];
}
void mergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    int n = 9;
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2, 1};
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
}