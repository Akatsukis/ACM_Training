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
const int maxn = 20;
string s[maxn];

inline bool ok(string &u, string v)
{
    int t = 0;
    for(auto c : v){
        if(c == u[t]){
            t++;
            if(t == SZ(u))return 1;
        }
    }
    return 0;
}


inline bool match(string &t, int id)
{
    int len = s[id].size();
    for(int st = 0; st < len; st++){
        if(ok(t, s[id].substr(st, len-st)+s[id].substr(0, st)))return 1;
    }
    return 0;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++)cin >> s[i];
        string ans;
        int len = s[0].size();
        for(int i = 1; i < (1<<len); i++){
            string t;
            for(int j = 0; j < len; j++)if((i>>j)&1)t += s[0][j];
            bool flg = 1;
            for(int j = 1; j < n; j++){
                if(!match(t, j)){
                    flg = 0;
                    break;
                }
            }
            if(flg){
                for(int st = 0; st < SZ(t); st++){
                    string p = t.substr(st, SZ(t)-st)+t.substr(0, st);
                    if(SZ(p) > SZ(ans))ans = p;
                    else if(SZ(p) == SZ(ans))ans = min(ans, p);
                }
                //cout << "t=" << t << " ans=" << ans << endl;
            }
        }
        if(!SZ(ans))puts("0");
        else cout << ans << endl;
    }
    return 0;
}

