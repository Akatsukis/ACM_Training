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
const int maxn = 1e5+10;
vector<int> G[maxn];
bool vis[maxn];
bool ban[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    list<int> lst;
    for(int i = 1; i <= n; i++) {
        lst.insert(lst.end(), i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            ans++;
            lst.erase(lst.begin());
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(auto v: G[u]) {
                    ban[v] = 1;
                }
                for(auto it = lst.begin(); it != lst.end();) {
                    if(!ban[*it]) {
                        q.push(*it);
                        vis[*it] = 1;
                        lst.erase(it++);
                    }
                    else {
                        it++;
                    }
                }
                for(auto v: G[u]) {
                    ban[v] = 0;
                }
            }
        }
    }
    printf("%d\n", ans-1);
    return 0;
}

