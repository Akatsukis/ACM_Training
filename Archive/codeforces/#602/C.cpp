#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6+10;
vector<vector<int>> sum;
vector<vector<char>> mp;
vector<string> ans;
char s[maxn];
int n, m;
 
inline int sqr(int x) {
    return x*x;
}
 
int cal(int x1, int y1, int x2, int y2) {
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
 
bool check(int r) {
    vector<vector<int>> cur(n+2, vector<int>(m+2, 0));
    set<pair<int, int>> st;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x = i+2*r, y = j+2*r;
            if(x <= n && y <= m && cal(i, j, x, y) == sqr(2*r+1)) {
                cur[i][j]++; cur[x+1][j]--; cur[i][y+1]--; cur[x+1][y+1]++;
                st.insert(make_pair(i+r, j+r));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cur[i][j] = cur[i][j-1]+cur[i-1][j]-cur[i-1][j-1]+cur[i][j];
            if(mp[i][j] == 'X' && cur[i][j] == 0) return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(st.count(make_pair(i+1, j+1))) ans[i][j] = 'X';
            else ans[i][j] = '.';
        }
    }
    return 1;
}
 
int main()
{
    scanf("%d%d", &n, &m);
    sum.resize(n+1);
    mp.resize(n+1);
    ans.resize(n+1);
    for(int i = 0; i <= n; i++) {
        sum[i].resize(m+1);
        mp[i].resize(m+1);
        ans[i].resize(m);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%s", s+1);
        for(int j = 1; j <= m; j++) {
            mp[i][j] = s[j];
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(s[j]=='X');
        }
    }
    int l = 0, r = min((n-1)/2, (m-1)/2), res = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    printf("%d\n", res);
    for(int i = 0; i < n; i++) {
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}
 
