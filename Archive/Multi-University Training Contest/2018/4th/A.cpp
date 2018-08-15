#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pli;
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
const ll INF64 = 0x7f7f7f7f7f7f7f7f;
const int maxn = 300+10;
const int maxk = 234;
bool vis[maxn];
int mx[maxk];
vector<ll> magic[maxk];
vector<int> pr;
set<pli> st;

void init()
{
    for(int i = 2; i < maxn; i++){
        if(!vis[i])pr.pb(i);
        for(int j = 0; j < SZ(pr) && i*pr[j] < maxn; j++){
            vis[i*pr[j]] = 1;
            if(i%pr[j] == 0)break;
        }
    }
    st.insert(mk(1, 1));
    while(!st.empty()){
        pli u = *st.begin(); st.erase(u);
        int l = 0, r = maxk-1, fr = maxk;
        while(l <= r){
            int m = (l+r)/2;
            if(u.se >= mx[m]){
                fr = m;
                r = m-1;
            }
            else l = m+1;
        }
        if(fr == maxk)continue;
        //printf("%lld, fr=%d\n", u.fi, fr);
        for(int i = 0; i < SZ(pr); i++){
            if(INF64/pr[i] < u.fi)continue;
            ll val = u.fi, fac = u.se;
            int cnt = 0;
            while(val%pr[i] == 0)val /= pr[i], cnt++;
            fac = fac/(cnt+1)*(cnt+2);
            if(!st.count(mk(u.fi*pr[i], fac)))st.insert(mk(u.fi*pr[i], fac));
        }
        mx[maxk-1] = max(mx[maxk-1], u.se);
        sort(mx, mx+maxk, greater<int>());
        for(int i = fr; i < maxk; i++)magic[i].pb(u.fi);
    }
}

int main()
{
    init();
    int T; sc(T);
    while(T--){
        ll n;
        int k;
        scanf("%lld%d", &n, &k);
        int l = 0, r = SZ(magic[k])-1, ret = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(n+m+1 <= magic[k][m]){
                ret = m;
                r = m-1;
            }
            else l = m+1;
        }
        printf("%lld\n", n+ret);
    }
    return 0;
}


