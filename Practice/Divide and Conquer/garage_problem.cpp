#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> start_time, end_time, min;

    int time = 5;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        start_time.push_back(a);
        end_time.push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        int e = start_time[i] - end_time[i];
        min.push_back(e);
    }

    sort(min.begin(), min.end());

    int count = 0;
    int k = n;
    int l = 0;
    while (k != 1 || time != 0)
    {
        count++;
        time -= min[l];
    }
    cout << time;
    return 0;
}