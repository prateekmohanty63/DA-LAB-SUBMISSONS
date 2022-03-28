#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    int PatternHashcode = 0;
    int n = pattern.size();
    int m = text.size();

    for (int i = 0; i < n; i++)
    {
        PatternHashcode += (pattern[i] - 96) * pow(10, n - 1 - i);
    }

    cout << PatternHashcode;
    int k = 0;

    int textHashcode = 0;

    int l = 0;
    int flag = 0;
    int g = 0;

    for (int i = 0; i < m; i++)
    {
        textHashcode += (text[i] - 96) * pow(10, n - g - 1);
        k++;

        g++;
        if (g == n - 1)
            g = 0;

        if (k != 0 && k % PatternHashcode == 0)
        {
            int o = 0;

            if (textHashcode == PatternHashcode)
            {
                while (l != n - 1)
                {
                    if (text[k - l] == pattern[n - l - 1])
                    {
                        o++;
                    }
                    l++;

                    if (o == n)
                    {
                        flag = 1;
                    }
                }
                l = 0;
            }
        }
        if (k == n)
        {
            textHashcode = 0;
        }
    }

    if (flag == 1)
        cout << "Patten found" << endl;

    else
        cout << "Pattern not found";

    return 0;
}