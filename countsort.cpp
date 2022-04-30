#include <bits/stdc++.h>

using namespace std;

void countsort(int arr[], int n)
{
    int k = *max_element(arr, arr + n);
    int min = *min_element(arr, arr + n);
    int count[(k - min) + 1];
    int s = (k - min) + 1;
    for (int i = 0; i < s; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int t = arr[i] - min;
        count[t] = count[t] + 1;
    }

    for (int i = 1; i < s; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    cout << endl;
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n = 9;
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2, 1};

    countsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}