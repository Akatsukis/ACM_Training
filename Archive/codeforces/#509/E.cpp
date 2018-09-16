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
int ans[maxn], tot[maxn];

int main()
{
    int n; sc(n);
    bool flg = 1;
    for(int i = 0; i < n-1; i++){
        int u, v;
        sc(u); sc(v);
        if(v != n)flg = 0;
        tot[u]++;
    }
    int now = 0;
    for(int i = 1; i <= n; i++){
        now += tot[i];
        if(now > i){
            flg = 0;
            break;
        }
    }
    if(flg){
        puts("YES");
        int id = n;
        ans[n] = id;
        set<int> st;
        for(int i = n-1; i >= 1; i--){
            if(tot[i]){
                id -= tot[i];
                ans[id] = i;
                st.insert(i);
            }
        }
        int used = 1;
        for(int i = 1; i <= n; i++){
            if(!ans[i]){
                while(st.count(used))used++;
                ans[i] = used;
                st.insert(used);
            }
        }
        for(int i = 1; i < n; i++){
            printf("%d %d\n", ans[i], ans[i+1]);
        }
    }
    else puts("NO");
    return 0;
}
