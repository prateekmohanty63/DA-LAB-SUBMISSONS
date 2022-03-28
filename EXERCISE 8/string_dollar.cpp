#include <iostream>
using namespace std;

int searchString(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();

    int i = 0;

    while (i <= n - m)
    {
        int j;
        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;

            if (j == m)
            {
                return i;
                i = i + m;
            }
            else if (j == 0)
                i++;

            else
                i = i + j;
        }
        i++;
    }
    return 0;
}

int main()
{
    string txt = "ABCEABCDABCEABCD";
    cout << "check the regex BC$ABCD where $ can be any symbol" << endl;
    string pat1 = "BC";
    string pat2 = "ABCD";
    int i1 = searchString(pat1, txt);
    int i2 = searchString(pat2, txt) + pat2.length() - 1;

    if (i1 < i2)
    {
        cout << "Pattern found at index " << i1 << " to index "
             << "i2";
        cout << " Value of $ will be"
             << " ";
        string a;
        for (int i = i1 + 1; i < i2 - 1; i++)
        {
            a += txt[i];
        }
        cout << a;
    }
    return 0;
}