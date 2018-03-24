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
const int maxn = 30;
double cost[maxn];
double r[maxn];
bool vis[maxn];
int n;

double spfa()
{
    memset(cost, 0 ,sizeof(cost)); 
    cost[0] = 1;
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 1; i <= 3; i++){
            if(u+i <= n && cost[u+i] < cost[u]*pow(1+r[i], i)+eps){
                cost[u+i] = cost[u]*pow(1+r[i], i);
                if(!vis[u+1])q.push(u+i);
            }
        }
        if(u+5 <= n && cost[u+5] < cost[u]*pow(1+r[4], 5)+eps){
            cost[u+5] = cost[u]*pow(1+r[4], 5);
            if(!vis[u+5])q.push(u+5);
        }
        vis[u] = 0;
    }
    return cost[n];
}

int main()
{
    sc(n);
    for(int i = 1; i <= 4; i++){
        scanf("%lf", &r[i]);
    }
    double ans = spfa();
    printf("%.5f\n", ans);
    return 0;
}

