#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;

    for (int i = 0; i < n; i++)
    {
        int a;
        vector<int> vec1;

        for (int j = 0; j < n; j++)
        {
            cin >> a;
            vec1.push_back(a);
        }
        matrix.push_back(vec1);
    }
    return 0;
}