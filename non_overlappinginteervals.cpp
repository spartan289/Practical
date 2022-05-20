#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sortcol(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }

    int compatible(vector<vector<int>> &intervals, int i)
    {
        for (int j = i - 1; j >= 0; j++)
        {
            if (intervals[1][j] <= intervals[0][i])
                return j;
        }
        return -1;
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
    }
};