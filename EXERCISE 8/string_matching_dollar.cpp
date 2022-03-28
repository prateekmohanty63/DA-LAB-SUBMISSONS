#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the pattern and the text" << endl;
    string pattern, text;
    cin >> pattern >> text;

    cout << "Enter the value of the dollar symbol" << endl;
    char e;
    cin >> e;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '$')
        {
            text[i] = e;
        }
    }
    int k = 0;
    int n = text.length();
    int m = pattern.length();

    // In KMP String pre processing is required
    int pre[10];
    // vector<int>pre;

    for (int i = 0; i < n; i++)
    {
        if (pattern[0] == text[i])
        {
            pre[k++] = i;
        }
    }

    //  for(int i=0;i<k;i++){
    //      cout<<pre[i]<<" ";
    //  }

    int l = 0;
    for (int i = pre[l]; i < n && l < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
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