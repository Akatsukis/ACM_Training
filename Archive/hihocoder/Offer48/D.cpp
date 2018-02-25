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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
int ans[maxn];
struct Line
{
    int x, y1, y2, id;
    bool f;
    bool operator < (const Line &rbs)
    {
        if(x != rbs.x)return x < rbs.x;
        else return f < rbs.f;
    }
}line[maxn*4];
int tag[maxn*4];

void pushdown(int k)
{
    if(tag[k]){
        tag[k*2+1] += tag[k];
        tag[k*2+2] += tag[k];
        tag[k] = 0;
    }
}

void update(int a, int b, int k, int l, int r, int v)
{
    if(a >= r || b <= l)return;
    if(a <= l && b >= r){
        tag[k] += v;
        return;
    }
    pushdown(k);
    int m = (l+r)/2;
    update(a, b, k*2+1, l, m, v);
    update(a, b, k*2+2, m, r, v);
}

int query(int a, int k, int l, int r)
{
    if(l == r-1)return tag[k];
    pushdown(k);
    int m = (l+r)/2;
    if(a < m)return query(a, k*2+1, l, m);
    else return query(a, k*2+2, m, r);
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        line[2*i].x = x1;
        line[2*i].y1 = y1;
        line[2*i].y2 = y2;
        line[2*i].f = 1;
        line[2*i].id = i;
        line[2*i+1].x = x2;
        line[2*i+1].y1 = y1;
        line[2*i+1].y2 = y2;
        line[2*i+1].f = 0;
        line[2*i+1].id = i;
    }
    sort(line, line+2*n);
    for(int i = 0; i < 2*n;){
        int now = 0;
        while(line[i+now].x == line[i].x){
            if(line[i+now].f == 1)update(line[i+now].y1, line[i+now].y2, 0, 0, maxn, 1);
            else update(line[i+now].y1, line[i+now].y2, 0, 0, maxn, -1);
            now++;
        }
        for(int j = i; j < i+now; j++){
            if(line[j].f == 1)ans[line[j].id] = query((line[j].y1+line[j].y2)/2, 0, 0, maxn)-1;
        }
        i += now;
        //printf("x=%d, y1=%d, y2=%d, f=%d\n", line[i].x, line[i].y1, line[i].y2, line[i].f);
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}

