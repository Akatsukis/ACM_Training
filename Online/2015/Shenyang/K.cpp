#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = (1<<8)+5;
map<int, ll> mp[maxn];
int n, q;

inline int bitcount(int x)
{
    int ret = 0;
    while(x){
        x -= x&(-x);
        ret++;
    }
    return ret;
}

inline void add(int u, int val, int cost)
{
    if(val < 0)return;
    mp[u][val] += cost;
}

inline void merge(int w, int u, int v)
{
    for(auto i = mp[u].begin(); i != mp[u].end(); i++){
        for(auto j = mp[v].begin(); j != mp[v].end(); j++){
            ll k = (i->se)*(j->se);
            add(w, (i->fi)+(j->fi), k*2);
            add(w, (i->fi)*(j->fi), k*2);
            add(w, (i->fi)-(j->fi), k);
            add(w, (j->fi)-(i->fi), k);
            if(i->fi != 0 && j->fi%i->fi==0)add(w, j->fi/i->fi, k);
            if(j->fi != 0 && i->fi%j->fi==0)add(w, i->fi/j->fi, k);
        }
    }
}

ll solve()
{
    ll ret = 0;
    for(int i = 1; i < (1<<n); i++){
        for(int j = i; j; j = (j-1)&i){
            int k = j^i;
            if(j < k)continue;
            merge(i, j, k);
        }
        if(mp[i].count(q)){
            int now = bitcount(i);
            ret += mp[i][q]*sqr(now);
        }
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(q);
        for(int i = 0; i < (1<<n); i++)mp[i].clear();
        for(int i = 0; i < n; i++){
            int x;
            sc(x);
            mp[1<<i][x] = 1;
        }
        ll ans = solve();
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

