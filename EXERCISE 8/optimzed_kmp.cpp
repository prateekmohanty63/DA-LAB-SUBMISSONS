#include <iostream>
#include <vector>

using namespace std;

// optimzed string matching algorithm

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    int k = 0;

    // In KMP String pre processing is required
    int pre[10];
    // vector<int>pre;

    for (int i = 0; i < n; i++)
    {
        if (b[0] == a[i])
        {
            pre[k++] = i;
        }
    }

    //  for(int i=0;i<k;i++){
    //      cout<<pre[i]<<" ";
    //  }
    int e = k;

    int l = 0;
    for (int i = pre[l]; i < n && l < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i + j] != b[j])
                break;

            if (j == m - 1)
            {
                cout << "Match found" << endl;
            }
        }
        l++;
    }

    return 0;
}