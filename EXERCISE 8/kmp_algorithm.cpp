#include <iostream>

using namespace std;

void LpsArray(string pattern, int lenPat, int *lps)
{
    int a = 0;

    // first char is always 0
    lps[0] = 0;

    int k = 1;
    int temp_length = 0;

    while (k < lenPat)
    {
        if (pattern[k] == pattern[temp_length])
        {
            temp_length++;
            lps[k] = temp_length;
            k++;
        }
        else
        {
            // condition when no match is found
            if (temp_length != 0)
            {
                temp_length = lps[temp_length - 1];
            }

            else
            {
                // if character not present
                lps[k] = 0;
                k++;
            }
        }
    }
}

void kmp_match(string pattern, string text)
{

    int m = pattern.length();
    int n = text.length();
    int lps[m];

    LpsArray(pattern, m, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        else if (i < n && pattern[i] != text[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == m - 1)
        {
            cout << "Pattern found at index: " << i - j << endl;
            j = lps[j - 1];
        }
    }
}

int main()
{
    string a, b;
    cout << "Enter the first and second string"
         << " ";
    cin >> a >> b;

    kmp_match(a, b);

    return 0;
}