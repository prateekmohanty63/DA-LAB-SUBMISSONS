#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }

    vector<int> res;
    res.push_back(vec1[0]);

    for (int i = 1; i < n; i++)
    {
        if (vec1[i] + res[i - 1] > 0)
        {
            res[i] = vec1[i] + res[i - 1];
        }
        else
            res[i] = res[i - 1];
    }

    cout << "Maximum Sub Array sum is: ";
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, res[i]);
    }
    cout << ans;
    return 0;
}