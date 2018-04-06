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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+1;
const int maxnode = 2e6+10;
const int maxc = 51;
int root[maxc];
int ls[maxnode], rs[maxnode], tr[maxnode];
int idx;
bool flg;

void init()
{
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    memset(tr, 0, sizeof(tr));
    memset(root, 0, sizeof(root));
    idx = 0;
}

void update(int &rt, int ql, int l, int r, int x)
{
    if(!rt){
        rt = ++idx;
        tr[rt] = x;
    }
    tr[rt] = min(tr[rt], x);
    if(l == r-1)return;
    int m = (l+r)>>1;
    if(ql < m)update(ls[rt], ql, l, m, x);
    else update(rs[rt], ql, m, r, x);
}

void query(int rt, int ql, int qr, int l, int r, int x)
{
    if(flg || !rt || l >= qr || r <= ql)return;
    if(l >= ql && r <= qr){
        if(tr[rt] <= x)flg = 1;
        return;
    }
    int m = (l+r)>>1;
    query(ls[rt], ql, qr, l, m, x);
    query(rs[rt], ql, qr, m, r, x);
}


int main()
{
    int opt;
    while(sc(opt) != EOF){
        if(opt == 0)init();
        else if(opt == 1){
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            update(root[c], y, 0, maxn, x);
        }
        else if(opt == 2){
            int x, y1, y2;
            scanf("%d%d%d", &x, &y1, &y2);
            int ans = 0;
            for(int i = 0; i <= 50; i++){
                flg = 0;
                query(root[i], y1, y2+1, 0, maxn, x);
                ans += flg;
            }
            printf("%d\n", ans);
        }
        else break;
    }
    return 0;
}

