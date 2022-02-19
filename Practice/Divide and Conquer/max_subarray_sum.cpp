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
    int max = -1;
    for (int i = 0; i < n - 1; i++)
    {

        int sum = vec1[i];

        for (int j = i + 1; j < n; j++)
        {
            if (sum > max)
                max = sum;

            sum += vec1[j];
                }
    }
    cout << max;
    return 0;
}