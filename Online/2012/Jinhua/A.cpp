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
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100100;
struct mines
{
    int x, y, d;
}p[maxn];
struct node
{
    int y, id;
    node(){}
    node(int a, int b):y(a), id(b){}
    bool operator < (const node &rhs)const
    {
        return y<rhs.y;
    }
};
int x[maxn];
multiset<node> st[maxn];
bool vis[maxn];
queue<int> q;
int n, m, tot;

void init()
{
    for(int i = 0; i < n; i++)st[i].clear();
    memset(vis, 0, sizeof(vis));
}

void bfs(int u)
{
    int ret = 1;
    q.push(u);
    vis[u] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        int l = lower_bound(x, x+tot, p[v].x-p[v].d)-x;
        int r = upper_bound(x, x+tot, p[v].x+p[v].d)-x;
        for(int i = l; i < r; i++){
            int lft = p[v].d-Abs(x[i]-p[v].x);
            multiset<node>::iterator it, itl, itr;
            itl = st[i].lower_bound(node(p[v].y-lft, 0));
            itr = st[i].upper_bound(node(p[v].y+lft, 0));
            for(it = itl; it != itr; it++){
                if(vis[it->id])continue;
                q.push(it->id);
                vis[it->id] = 1;
                ret++;
            }
            st[i].erase(itl, itr);
        }
    }
    printf("%d\n", ret);
}

int main()
{
    int kase = 1;
    while(scanf("%d", &n) != EOF && n){
        init();
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].d);
            x[i] = p[i].x;
        }
        sort(x, x+n);
        tot = unique(x, x+n)-x;
        for(int i = 0; i < n; i++){
            int id = lower_bound(x, x+tot, p[i].x)-x;
            st[id].insert(node(p[i].y, i));
        }
        sc(m);
        for(int i = 0; i < m; i++){
            int u;
            sc(u);
            u--;
            if(vis[u]){
                printf("0\n");
                continue;
            }
            bfs(u); 
        }
    }
    return 0;
}

