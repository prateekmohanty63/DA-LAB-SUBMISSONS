#include <iostream>
#include <vector>
using namespace std;

void matrixInput(vector<vector<int>> &mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            row.push_back(a);
        }
        mat.push_back(row);
    }
}

void printMatrix(vector<vector<int>> mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_muliply(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &mat3)
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
    int n;
    cin >> n;
    vector<vector<int>> mat1, mat2;
    matrixInput(mat1, n);
    matrixInput(mat2, n);

    vector<vector<int>> mat3(n, vector<int>(n, 0));

    matrix_muliply(mat1, mat2, mat3);

    printMatrix(mat3, n);

    return 0;
}