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
vector<int> vec, alt;
vector<pii> ans;
int a[maxn];

int main()
{
    int n;
    sc(n); 
    int st = 0, ls = 0, len = 0;
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        if(a[i] == 1)vec.pb(i);
        else{
            alt.pb(i);
            if(!ls)st = i;
            else{
                ans.pb(mk(ls, i));
                a[ls]--; a[i]--;
                len++;
            }
            ls = i;
        }
    }
    if(vec.size() >= 1){
        ans.pb(mk(vec[0], st));
        a[vec[0]]--; a[st]--;
        len++;
    }
    if(vec.size() >= 2){
        ans.pb(mk(vec[1], ls));
        a[vec[1]]--; a[ls]--;
        len++;
    }
    int cnt = min(SZ(vec), 2);
    for(auto u : alt){
        while(a[u] && cnt < SZ(vec)){
            ans.pb(mk(vec[cnt], u));
            a[vec[cnt]]--; a[u]--;
            cnt++;
        }
    }
    if(cnt == SZ(vec)){
        printf("YES %d\n", len);
        printf("%d\n", SZ(ans));
        for(auto p : ans)printf("%d %d\n", p.fi, p.se);
    }
    else puts("NO");
    return 0;
}

