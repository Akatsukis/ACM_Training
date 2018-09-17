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
const int maxn = 2e5+10;
bool vis[maxn];
int n, tot;

void del(int pos)
{
    if(tot == n-1)return;
    printf("2 %d\n", pos);
    vis[pos] = 1; tot++;
}

void comb(int x, int y)
{
    if(tot == n-1)return;
    printf("1 %d %d\n", x, y);
    vis[x] = 1; tot++;
}

int main()
{
    vector<pii> pos, neg, zero;
    sc(n);
    for(int i = 1; i <= n; i++){
        int x; sc(x);
        if(x < 0)neg.pb(mk(x, i));
        else if(x > 0)pos.pb(mk(x, i));
        else zero.pb(mk(x, i));
    }
    sort(ALL(pos));
    sort(ALL(neg));
    sort(ALL(zero));
    if(SZ(zero) >= 1){
        if(SZ(neg)%2 == 0){
            for(int i = 1; i < SZ(zero); i++){
                comb(zero[i].se, zero[0].se);
            }
            del(zero[0].se);
        }
        else{
            int id = neg[SZ(neg)-1].se;
            for(int i = 0; i < SZ(zero); i++){
                comb(zero[i].se, id);
            }
            del(id);
        }
    }
    else{
        if(SZ(neg)%2 != 0){
            int id = neg[SZ(neg)-1].se;
            del(id);
        }
    }
    int st = 1;
    while(vis[st])st++;
    for(int i = 1; i <= n; i++){
        if(vis[i] || i == st)continue;
        else comb(i, st);
    }
    return 0;
}

