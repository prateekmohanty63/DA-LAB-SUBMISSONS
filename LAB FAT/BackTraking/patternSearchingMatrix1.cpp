#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<vector<int>> &m , int i , int j , string p , string psf ,bool &ans){
    if(ans) return;
    if(i >= m.size() || j >= m[i].size() || m[i][j] < 0) return;
    if(p == psf){
        ans = true;
        return;
    }
    m[i][j] = -m[i][j];
    if(i != m.size() - 1)
        solve(m , i + 1 , j , p , psf + to_string(m[i + 1][j]) , ans);
    if(i != 0)
        solve(m , i - 1, j , p , psf + to_string(m[i - 1][j]) , ans);
    if(j!=0)
        solve(m , i , j - 1 , p , psf + to_string(m[i][j - 1]) , ans);
    if(j != m[i].size() - 1)
        solve(m , i , j + 1, p , psf + to_string(m[i][j + 1]) , ans);

    m[i][j] = -m[i][j];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    string pattern;
    cin >> pattern;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool ans = false;
            solve(matrix , i , j , pattern , to_string(matrix[i][j]),ans);
            if(ans) {cout << "Pattern Found"; exit(0);}
        }
    }
    cout << "Pattern Not Found";
}