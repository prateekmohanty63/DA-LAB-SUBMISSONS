#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements in the array" << endl;
    cin >> n;
    vector<int> vec1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }
    int count = 0;

    cout << "Finding the inversion elements we get" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec1[i] > vec1[j])
            {
                cout << "(" << i + 1 << "," << j + 1 << ")" << endl;
                count++;
            }
        }
    }

    cout << "The number of inversion elements are: ";
    cout << count;
    return 0;
}