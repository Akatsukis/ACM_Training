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
set<pii> st;
int ans[maxn];

int main()
{
    int n, m, d;
    sc(n); sc(m); sc(d);
    for(int i = 1; i <= n; i++){
        int x; sc(x);
        st.insert(mk(x, i));
    }
    int tot = 1, now = 0;
    while(!st.empty()){
        auto it = st.lower_bound(mk(now+1, 0));
        if(it == st.end()){
            tot++;
            now = 0;
            continue;
        }
        ans[it->se] = tot;
        now = it->fi+d;
        st.erase(it++);
    }
    printf("%d\n", tot);
    for(int i = 1; i <= n; i++)printf("%d%c", ans[i], " \n"[i==n]);
    return 0;
}

