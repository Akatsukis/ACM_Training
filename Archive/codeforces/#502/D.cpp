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
const int INF = 0x3f3f3f3f;
const int maxn = 15;
int num[1<<maxn];
int w[maxn];
map<int, int> mp[1<<maxn];

int main()
{
    int n, m, q;
    sc(n); sc(m); sc(q);
    for(int i = 0; i < n; i++)sc(w[i]);
    for(int i = 0; i < m; i++){
        char s[maxn];
        scanf("%s", s);
        int bit = 0;
        for(int j = 0; j < n; j++)if(s[j] == '1')bit += (1<<j);
        num[bit]++;
    }
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < (1<<n); j++){
            if(!num[j])continue;
            int tot = 0;
            for(int k = 0; k < n; k++){
                if(((i>>k)&1) == ((j>>k)&1))tot += w[k];
            }
            mp[i][tot] += num[j]; 
        }
    }
    for(int i = 0; i < (1<<n); i++){
        int pre = 0;
        for(auto &u : mp[i]){
            u.se += pre;
            pre = u.se;
            //printf("mp[%d][%d]=%d\n", i, u.fi, u.se);
        }
        mp[i][INF] = pre;
    }
    for(int i = 0; i < q; i++){
        char s[maxn];
        int val;
        scanf("%s%d", s, &val);
        int bit = 0;
        for(int j = 0; j < n; j++)if(s[j] == '1')bit += (1<<j);
        auto it = mp[bit].upper_bound(val);
        if(it == mp[bit].begin())printf("0\n");
        else printf("%d\n", (--it)->se);
    }
    return 0;
}


