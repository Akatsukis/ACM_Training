#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(n == 1 && m == 1) {
        printf("0\n");
        return 0;
    }
    bool rev = 0;
    if(n > m) {
        swap(n, m);
        rev = 1;
    }
    vector<vector<int>> mat(n, vector<int>(m, 1));
    int cur = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] *= cur;
        }
        cur++;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            mat[j][i] *= cur;
        }
        cur++;
    }
    if(!rev) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d%c", mat[i][j], " \n"[j==m-1]);
            }
        }
    }
    else {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d%c", mat[j][i], " \n"[j==n-1]);
            }
        }
    }
    return 0;
}

