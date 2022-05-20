#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}
int findKthsmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int j = randomPartition(arr, l, r);
        if (j - l == k - 1)
            return arr[j];
        if (j - l > k - 1)
            return findKthsmallest(arr, l, j - 1, k);
        return findKthsmallest(arr, j + 1, r, k - j + l - 1);
    }
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << findKthsmallest(arr, 0, n - 1, k);
    return 0;
}