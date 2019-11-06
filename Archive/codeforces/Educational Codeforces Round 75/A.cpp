#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<bool> vis(26, 0);
        for(int i = 0; i < n; ) {
            if(i+1 < n && s[i] == s[i+1]) {
                i += 2;
            }
            else {
                vis[s[i]-'a'] = 1;
                i++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(vis[i])putchar('a'+i);
        }
        puts("");
    }
    return 0;
}

