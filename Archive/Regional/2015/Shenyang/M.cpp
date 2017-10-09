#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e6 + 10;
vector<vector<pii> > G(maxn);
ll d[2][maxn];

priority_queue<pii, vector<pii>, greater<pii> > q;
void dij(int s, int n, int x)
{
    while(!q.empty())q.pop();
    fill(d[x] + 1, d[x] + n + 1, INF64);
    d[x][s] = 0;
    q.push(mk(0, s));
    while(!q.empty()){
        pii p = q.top();q.pop();
        int v = p.se;
        if(d[x][v] < p.fi)continue;
        for(int i = 0; i < (int)G[v].size(); i++){
            pii e = G[v][i];
            if(d[x][e.fi] > d[x][v] + e.se){
                d[x][e.fi] = d[x][v] + e.se;
                q.push(mk(d[x][e.fi], e.fi));
            }
        }
    }
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        memset(d, 0, sizeof(d));
        for(int i = 0; i <= n + m; i++)G[i].clear();
        int cur = n;
        for(int i = 1; i <= m; i++){
            int t, p;
            scanf("%d%d", &t, &p);
            for(int j = 0; j < p; j++){
                int x;
                scanf("%d", &x);
                G[n + i].pb(mk(x, 0));
                G[x].pb(mk(n + i, t));
            }
        }
        dij(1, n + m, 0);
        dij(n, n + m, 1);
        ll ans = INF64;
        for(int i = 1; i <= n; i++){
            ll now = max(d[0][i], d[1][i]);
            //printf("d1[%d]=%lld d2[%d]:%lld\n", i, d1[i], i, d2[i]);
            if(now < ans){
                ans = now;
            }
        }
        if(ans == INF64){
            printf("Case #%d: Evil John\n", kase++);
            continue;
        }
        printf("Case #%d: %lld\n", kase++, ans);
        bool fst = 1;
        for(int i = 1; i <= n; i++){
            if(max(d[0][i], d[1][i]) == ans){
                if(fst)fst = 0;
                else printf(" ");
                printf("%d", i);
            }
        }
        printf("\n");
    }
	return 0;
}


