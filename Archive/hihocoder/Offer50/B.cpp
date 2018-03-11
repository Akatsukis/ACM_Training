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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
struct pos
{
    int l, r, id;
    bool operator < (const pos&rbs)const
    {
        if(min(l, r) != min(rbs.l, rbs.r))return min(l, r)<min(rbs.l, rbs.r);
        else if(max(l, r) != max(rbs.l, rbs.r))return max(l, r)<max(rbs.l, rbs.r);
        else return id>rbs.id;
    }
};
priority_queue<pos> pq;
int a[maxn];
bool vis[maxn];

void Push(pos x)
{
    if(x.l){
        int id = x.id-x.l/2-1;
        int l = (x.l-1)/2, r = (x.l)/2;
        if(!vis[id])pq.push((pos){l, r, id}); 
        vis[id] = 1;
        //printf("l=%d r=%d id=%d\n", l, r, id);
    }
    if(x.r){
        int id = x.id+(x.r+1)/2;
        int l = (x.r-1)/2, r = (x.r)/2;
        if(!vis[id])pq.push((pos){l, r, id});
        vis[id] = 1;
        //printf("l=%d r=%d id=%d\n", l, r, id);
    }
}

int main()
{
    int n, m, k;
    sc(n); sc(m); sc(k);
    for(int i = 1; i <= m; i++){
        sc(a[i]);
    }
    a[0] = 0, a[m+1] = n+1;
    sort(a, a+m+2);
    for(int i = 1; i <= m; i++){
        Push((pos){a[i]-a[i-1]-1, a[i+1]-a[i]-1, a[i]});
    }
    for(int i = 0; i < k; i++){
        pos now = pq.top(); pq.pop();
        printf("%d\n", now.id);
        Push(now);
    }
    return 0;
}

