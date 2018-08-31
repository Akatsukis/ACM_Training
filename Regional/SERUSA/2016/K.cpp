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
const int maxn = 1e6+10;
int a[maxn];
int tr[2][maxn];
int sz;

int get_max(int x, int t)
{
    int ret = 0;
    while(x){
        ret = max(ret, tr[t][x]);
        x -= x&-x;
    }
    return ret;
}

void update(int x, int t, int val)
{
    while(x <= sz){
        tr[t][x] = max(tr[t][x], val);
        x += x&-x;
    }
}

int main()
{
    int n; sc(n);
    vector<int> vec;
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        vec.pb(a[i]);
    }
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    sz = vec.size();
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int id = lower_bound(ALL(vec), a[i])-vec.begin()+1;
        int u = get_max(sz-id, 1)+1;
        update(id, 0, u);
        int v = get_max(id-1, 0)+1;
        update(sz-id+1, 1, v);
        ans = max(ans, max(u, v));
    }
    printf("%d\n", ans);
    return 0;
}


