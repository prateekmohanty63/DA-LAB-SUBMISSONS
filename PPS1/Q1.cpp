#include <iostream>
#include <vector>
using namespace std;

// Selection sort

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

    cout << "Vector before sorting" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << vec1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vec1[j] < vec1[index])
                index = j;
        }
        swap(vec1[i], vec1[index]);
    }

    cout << "Vector after sorting" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << vec1[i] << " ";
    }

    return 0;
}