#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

vector<char> merge(vector<char> left, vector<char> right)
{
    vector<char> result;
    int right_side_counter = 0, left_side_counter = 0;
    while ((int)left.size() > 0 || (int)right.size() > 0)
    {
        if ((int)left.size() > 0 && (int)right.size() > 0)
        {
            if ((int)left.front() <= (int)right.front())
            {
                result.push_back((int)left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back((int)right.front());
                right.erase(right.begin());
            }
        }

        else if ((int)left.size() > 0)
        {
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
        }
        else if ((int)right.size() > 0)
        {
            for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
            break;
        }
    }
    return result;
}

vector<char> mergeSort(vector<char> m, int &leftCount, int &rightCount)
{
    if (m.size() <= 1)
        return m;

    vector<char> left, right, result;
    int middle = ((int)m.size() + 1) / 2;

    for (int i = 0; i < middle; i++)
    {
        left.push_back(m[i]);
    }

    for (int i = middle; i < (int)m.size(); i++)
    {
        right.push_back(m[i]);
    }

    leftCount++;
    left = mergeSort(left, leftCount, rightCount);

    rightCount++;
    right = mergeSort(right, leftCount, rightCount);

    result = merge(left, right);

    return result;
}
int main()
{
    int a = 0, b = 0;
    int n;
    cout << "Enter the number of elements in the vector array: \n";
    cin >> n;
    vector<char> v;
    cout << "Enter the elements of the vector array: \n";
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        v.push_back(x);
    }
    cout << "The unsorted vector array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    cout << "The sorted vector array using merge sort is: \n";
    vector<char> result = mergeSort(v, a, b);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
    cout << a << " " << b;
    return 0;
}