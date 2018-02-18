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
#define pr(x) printf(">>>"#x:"%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int P[5], V[5];
int A[5], B[5], C[5], D[5];

bool hit(int u, int v)
{
    double now = A[v]*tan(P[u]);
    if(now >= D[v] && now <= B[v])return true;
    if(P[u] >= 0 && D[v] >= 0){
        now = D[v]/tan(P[u]);
        if(now >= A[v] && now <= C[v])return true;
    }
    else if(P[u] < 0 && B[v] < 0){
        now = abs(B[v])/tan(P[u]);
        if(now >= A[v] && now <= C[v])return true;
    }
    return false;
}

struct Node
{
    double t;
    int tor, shp;
};

bool cmp(Node a, Node b)
{
    return a.t < b.t;
}


int main()
{
    int T;
    sc(T);
    while(T--){
        for(int i = 0; i < 3; i++){
            sc(P[i]);sc(V[i]);
        }
        for(int i = 0; i < 3; i++){
            sc(A[i]);sc(B[i]);sc(C[i]);sc(D[i]);
        }
        vector<Node> target;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(hit(i, j)){
                    //printf(">>>i=%d, j=%d\n", i, j);
                    double now = A[j]*tan(P[i]);
                    if(now >= D[j] && now <= B[j]){
                        target.pb({A[j]/(V[i]*cos(P[i])), i, j});
                    }
                    else{
                        if(P[i] >= 0)target.pb({D[j]/(V[i]*sin(P[i])), i, j});
                        else target.pb({B[j]/(V[i]*sin(P[i])), i, j});
                    }
                }
            }
        }
        bool vis[5], used[5];
        memset(vis, 0, sizeof(vis));
        memset(used, 0, sizeof(used));
        sort(ALL(target), cmp);
        int ans = 0;
        for(int i = 0; i < (int)target.size(); i++){
            int u = target[i].shp, v = target[i].tor;
            if(!vis[u] && !used[v]){
                ans++;
                vis[u] = 1;
                used[v] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

