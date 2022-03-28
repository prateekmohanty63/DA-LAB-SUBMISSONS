#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int amount;
    cin >> amount;
    int n;
    cin >> n;
    vector<int> vec1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }

    // in greedy, my approach would be keep taking the max value coin till the amount becomes less than the max coin value
    // then move to the next lower denomination coin

    int temp = amount;
    sort(vec1.begin(), vec1.end(), greater<int>());
    int k = 0;

    int coinCount = 0;

    while (temp != 0)
    {
        /* code */

        if (temp >= vec1[k])
        {
            coinCount++;
            temp -= vec1[k];
        }
        else
        {
            k++;
        }
    }
    cout << coinCount;

    return 0;
}