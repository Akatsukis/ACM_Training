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
long long area[maxn];

void ask(int t, int i, int j, int k) {
    printf("%d %d %d %d\n", t, i, j, k);
    fflush(stdout);
}

bool cmp(int u, int v) {
    return area[u] < area[v];
}


bool cmp1(int u, int v) {
    return area[u] > area[v];
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> l, r;
    for(int i = 3; i <= n; i++) {
        ask(2, 1, 2, i);
        int sgn;
        scanf("%d", &sgn);
        if(sgn == 1)l.push_back(i);
        else r.push_back(i);
    }
    int mxl = -1, mxr = -1;
    for(auto v: l) {
        ask(1, 1, 2, v);
        scanf("%lld", &area[v]);
        if(mxl == -1 || area[v] > area[mxl])mxl = v;
    }
    for(auto v: r) {
        ask(1, 1, 2, v);
        scanf("%lld", &area[v]);
        if(mxr == -1 || area[v] > area[mxr])mxr = v;
    }
    //printf("l: ");
    //for(auto v: l) printf("%d ", v);
    //puts("");
    //printf("r: ");
    //for(auto v: r) printf("%d ", v);
    //puts("");
    //printf("mxl=%d, mxr=%d\n", mxl, mxr);
    vector<int> ll, lr, rl, rr;
    for(auto v: l) {
        if(v == mxl)continue;
        ask(2, 1, mxl, v);
        int sgn;
        scanf("%d", &sgn);
        if(sgn == 1)ll.push_back(v);
        else lr.push_back(v);
    }
    for(auto v: r) {
        if(v == mxr)continue;
        ask(2, 1, mxr, v);
        int sgn;
        scanf("%d", &sgn);
        if(sgn == 1)rl.push_back(v);
        else rr.push_back(v);
    }
    sort(ll.begin(), ll.end(), cmp);
    sort(lr.begin(), lr.end(), cmp1);
    sort(rl.begin(), rl.end(), cmp);
    sort(rr.begin(), rr.end(), cmp1);
    vector<int> ans;
    ans.push_back(1);
    for(auto v: ll) {
        ans.push_back(v);
    }
    if(mxl != -1)ans.push_back(mxl);
    for(auto v: lr) {
        ans.push_back(v);
    }
    ans.push_back(2);
    for(auto v: rl) {
        ans.push_back(v);
    }
    if(mxr != -1)ans.push_back(mxr);
    for(auto v: rr) {
        ans.push_back(v);
    }
    reverse(ans.begin(), ans.end());
    printf("0 ");
    for(int i = 0; i < n; i++) {
        if(ans[i] == 1) {
            for(int j = 0; j < n; j++) {
                printf("%d%c", ans[(i+j)%n], " \n"[j==n-1]);
            }
            break;
        }
    }
    fflush(stdout);
    return 0;
}

