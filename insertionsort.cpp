#include <bits/stdc++.h>

using namespace std;

void insertionsort(int A[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        key = A[i];
        while (j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int n = 9;
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2, 1};

    insertionsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
}