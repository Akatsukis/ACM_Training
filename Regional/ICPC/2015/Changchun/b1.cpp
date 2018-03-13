#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6 + 10;
int n, m, k;
struct Event
{
    int x, y1, y2;
    int add;
};

struct IntervalTreeNode
{
    ll tag, bit1, bit2;
};

Event evt[maxn * 2 + 1];
IntervalTreeNode tree[(maxn+10)<<2];
int id[maxn * 2];

bool cmp(const Event &a, const Event &b)
{
    if(a.x < b.x)return 1;
    return 0;
}

void pushdown(int k, int l, int r)
{
    if(tree[k].tag){
        if(l != r - 1){
            tree[k * 2 + 1].tag += tree[k].tag;
            tree[k * 2 + 2].tag += tree[k].tag;
        }
        tree[k].bit2 += 2 * tree[k].bit1 * tree[k].tag + tree[k].tag * tree[k].tag;
        //printf("k=%d l=%d r=%d bit2:%d\n", k, l, r, tree[k].bit2);
        //printf("tree[%d].bit2=%lld\n", k, tree[k].bit2);
        tree[k].bit1 += tree[k].tag;
    }
    tree[k].tag = 0;
}

void pushup(int k, int l, int r)
{
    tree[k].bit1 = tree[k * 2 + 1].bit1 + tree[k * 2 + 2].bit1;
    tree[k].bit2 = tree[k * 2 + 1].bit2 + tree[k * 2 + 2].bit2;
}

void update(int a, int b, int k, int l, int r, ll c)
{
    //printf("a=%d b=%d k=%d l=%d r=%d c=%lld\n", a, b, k, l, r, c);
    if(r <= a || l >= b)return;
    if(l >= a && r <= b){
        tree[k].tag += c;
        pushdown(k, l, r);
        return;
    }
    int m = (l + r) / 2;
    pushdown(k, l, r);
    update(a, b, k * 2 + 1, l, m, c);
    update(a, b, k * 2 + 2, m, r, c);
    pushup(k, l, r);
}

void work()
{
    memset(tree, 0, sizeof(tree));
    sc(n);sc(m);sc(k);
    int x = 0, y = 0;
    n = m = 0;
    for(int i = 0; i < k; i++){
        char s[2];
        int step;
        scanf("%s%d", s, &step);
        if(s[0] == 'U'){
            int y1 = y, y2 = y + step;;
            y += step;
            evt[n].add = 1, evt[n].x = x, evt[n].y1 = y1, evt[n].y2 = y2;
            n++;
        }
        else if(s[0] == 'D'){
            int y1 = y - step, y2 = y;
            y -= step;
            evt[n].add = -1, evt[n].x = x, evt[n].y1 = y1, evt[n].y2 = y2;
            n++;
        }
        else if(s[0] == 'L'){
            id[m++] = y;
            x -= step;
        }
        else if(s[0] == 'R'){
            id[m++] = y;
            x += step;
        }
    }
    sort(id, id + m);
    for(int i = 0; i < n; i++){
        evt[i].y1 = lower_bound(id, id + m, evt[i].y1) - id;
        evt[i].y2 = lower_bound(id, id + m, evt[i].y2) - id;
    }
    sort(evt, evt + n, cmp);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i && evt[i].x > evt[i - 1].x){
            ans += (long long)(evt[i].x - evt[i - 1].x) * tree[0].bit2;
            //printf("tree[0].bit1=%d tree[0].bit2=%d\n", tree[0].bit1, tree[0].bit2);
        }
        //printf("ans[%d]=%lld\n", i, ans);
        update(evt[i].y1, evt[i].y2, 0, 0, m - 1, evt[i].add);
        printf("tree[0].bit1=%lld tree[0].bit2=%lld\n", tree[0].bit1, tree[0].bit2);
        //printf("evt[%d].y1:%d evt[%d].y2:%d evt[%d].add:%d evt[%d].x:%d\n", i, evt[i].y1, i, evt[i].y2, i, evt[i].add, i, evt[i].x);
    }
    printf("%lld\n", ans);
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        printf("Case #%d: ", kase++);
        work();
    }
	return 0;
}


