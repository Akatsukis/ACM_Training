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
const int maxn = 1e3+10;
int tb[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, m, k;
        sc(n); sc(m); sc(k);
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            tb[i] = 0;
            for(int j = 0; j < m; j++){
                if(s[j] == 'A')tb[i] |= (1<<j);
            }
        }
        int ans = 0;
        for(int i = 1; i < (1<<m); i++){
            map<int, int> mp;
            for(int j = 0; j < n; j++){
                mp[tb[j]&i]++;
            }
            int tot = n*(n-1)/2;
            for(auto u : mp)tot -= u.se*(u.se-1)/2;
            if(tot >= k)ans++;
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}


