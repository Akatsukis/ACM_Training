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
constexpr int maxn = 2e5+10;
struct data {
    int v, pos;
    bool operator < (const data &rhs) const {
        if(v != rhs.v) return v > rhs.v;
        else return pos < rhs.pos;
    }
}a[maxn];
vector<pair<int, int>> qry[maxn];
int ans[maxn];
int bit[maxn];
int b[maxn];

void add(int x) {
    while(x < maxn) {   
        bit[x]++;
        x += x&(-x);
    }
}

int sum(int x) {
    int ret = 0;
    while(x) {
        ret += bit[x];
        x -= x&(-x);
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].v);
        a[i].pos = i;
        b[i] = a[i].v;
    }
    sort(a+1, a+1+n);
    //for(int i = 1; i <= n; i++) {
        //printf("pos=%d\n", a[i].pos);
    //}
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {    
        int k, pos;
        scanf("%d%d", &k, &pos);
        qry[k].push_back(make_pair(pos, i));
    }
    for(int i = 1; i <= n; i++) {
        add(a[i].pos);
        for(auto p: qry[i]) {
            int l = 1, r = n, res = 1;
            while(l <= r) {
                int m = (l+r)/2;
                if(sum(m) >= p.first) {
                    res = m;
                    r = m-1;
                }
                else l = m+1;
            }
            //printf("id=%d, res=%d a[res].v=%d\n", p.second, res, b[res]);
            ans[p.second] = b[res];
        }
    }
    for(int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

