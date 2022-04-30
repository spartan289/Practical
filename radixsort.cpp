#include <bits/stdc++.h>

using namespace std;

void countsort(int arr[], int n, int j)
{
    int k = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    int count[10] = {0};
    int s = 10;

    for (int i = 0; i < n; i++)
    {
        int t = (arr[i] / j) % 10;
        count[t] = count[t] + 1;
    }

    for (int i = 1; i < s; i++)
    {
        count[i] += count[i - 1];
    }

    cout << endl;
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / j) % 10] - 1] = arr[i];
        count[(arr[i] / j) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int maxEle = *max_element(arr, arr + n);
    cout << maxEle;
    for (int i = 1; maxEle / i > 0; i *= 10)
        countsort(arr, n, i);
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    // Function Call
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    return 0;
}