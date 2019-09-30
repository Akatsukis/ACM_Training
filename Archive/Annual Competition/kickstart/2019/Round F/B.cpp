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
const int maxn = 1e5+10;
vector<int> skill[maxn];
map<vector<int>, int> mp;

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        mp.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            skill[i].clear();
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k; j++) {
                int x;
                scanf("%d", &x);
                skill[i].push_back(x);
            }
            sort(skill[i].begin(), skill[i].end());
            mp[skill[i]]++;
        }
        long long ans = 1LL*n*(n-1);
        for(int i = 0; i < n; i++) {
            int S = (1<<skill[i].size())-1;
            for(int j = S; j; j = (j-1)&S) {
                vector<int> vec;
                for(int k = 0; k < 5; k++) {
                    if(j>>k&1) vec.push_back(skill[i][k]);
                }
                if(mp.count(vec))ans -= mp[vec];
            }
            ans++;
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

