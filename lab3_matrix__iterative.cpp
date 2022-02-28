#include <iostream>
using namespace std;
#include <vector>
void read_matrix(vector<vector<int>> &mat, int n)
{
    int ele;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            cin >> ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
}
void print_matrix(vector<vector<int>> mat)
{
    int n = mat.size(), i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}
void matrix_multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2,
                     vector<vector<int>> &mat3)
{
    int i, j, k, n;
    n = mat1.size();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main()
{
    vector<vector<int>> mat1, mat2;
    int i, j, n;
    cin >> n;
    read_matrix(mat1, n);
    read_matrix(mat2, n);
    vector<vector<int>> mat3(n, vector<int>(n, 0));
    matrix_multiply(mat1, mat2, mat3);
    print_matrix(mat3);
}