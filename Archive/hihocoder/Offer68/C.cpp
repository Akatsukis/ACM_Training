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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
int a[maxn];
int nxt[maxn];
int col[maxn];
int dist[maxn];
int n;

int bfs(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u+1 <= n && dist[u+1] > dist[u]+1){
            dist[u+1] = dist[u]+1;
            q.push(u+1);
        }
        if(nxt[u] && dist[nxt[u]] > dist[u]+1){
            dist[nxt[u]] = dist[u]+1;
            q.push(nxt[u]);
        }
    }
    return dist[n];
}

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    for(int i = n; i >= 1; i--){
        nxt[i] = col[a[i]];
        col[a[i]] = i;
    }
    printf("%d\n", bfs(1));
    return 0;
}

