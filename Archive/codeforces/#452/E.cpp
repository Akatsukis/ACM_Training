#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5+10;
vector<int> vi;
bool vis[maxn];
int pre[maxn], nxt[maxn], a[maxn], sz[maxn], pos[maxn];
struct pnt
{
    int x;
    bool operator < (const pnt& rbs)const
    {
        if(sz[x] != sz[rbs.x])return sz[x] < sz[rbs.x];
        return pos[x] > pos[rbs.x];
    }
};
priority_queue<pnt> pq;
int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    for(int i = 1; i <= n;){
        int cnt = 1;
        while(i+cnt <= n && a[i+cnt] == a[i])cnt++;
        sz[i] = cnt;
        pos[i] = i;
        pq.push(pnt{i});
        vi.pb(i);
        i += cnt;
    }
    for(int i = 0; i < (int)vi.size(); i++){
        if(!i)pre[vi[i]] = 0;
        else pre[vi[i]] = vi[i-1];
        if(i == (int)vi.size()-1)nxt[vi[i]] = 0;
        else nxt[vi[i]] = vi[i+1];
    }
    int cnt = n, ans = 0;;
    while(!pq.empty()){
        int u = pq.top().x;pq.pop();
        if(vis[u])continue;
        ans++;
        //printf("u=%d\n", u);
        vis[u] = 1;
        if(a[pre[u]] == a[nxt[u]] && a[pre[u]]){
            cnt++;
            sz[cnt] = sz[pre[u]] + sz[nxt[u]];
            a[cnt] = a[pre[u]];
            pos[cnt] = pos[pre[u]];
            nxt[pre[pre[u]]] = cnt;
            pre[nxt[nxt[u]]] = cnt;
            nxt[cnt] = nxt[nxt[u]];
            pre[cnt] = pre[pre[u]];
            vis[pre[u]] = 1;
            vis[nxt[u]] = 1;
            pq.push(pnt{cnt});
        }
        else{
            pre[nxt[u]] = pre[u];
            nxt[pre[u]] = nxt[u];
        }
    }
    printf("%d\n", ans);
    return 0;
}

