#include <iostream>

using namespace std;

// string matching

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i + j] != b[j])
                break;

            if (j == m - 1)
            {
                cout << "Match found at index " << i << endl;
                break;
            }
        }
    }

    return 0;
}