#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define fi first
#define se second
const int maxn = (1<<18)+10;
string s;
unordered_map<string, int> mp[2];
 
string solve(const string &now, int n, int t)
{
    string ret(n/2, '0');
    for(int i = 0; i < n; i += 2){
        int u = now[i]-'0', v = now[i+1]-'0';
        if(t == 0 && (u&v) == 1)ret[i/2] = '1';
        if(t == 1 && (u|v) == 1)ret[i/2] = '1';
        if(t == 2 && (u^v) == 1)ret[i/2] = '1';
    }
    return ret;
}
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> s;
    int cur = 0, nxt = 1;
    mp[cur][s] = 1;
    for(int i = (1<<n); i != 1; i /= 2){
        for(auto u : mp[cur]){
            for(int j = 0; j < 3; j++){
                mp[nxt][solve(u.fi, i, j)] += u.se;
            }
        }
        swap(cur, nxt);
        mp[nxt].clear();
    }
    string s = "1";
    cout << mp[cur][s] << endl;
    return 0;
}
