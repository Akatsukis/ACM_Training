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
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int x[4], y[4], r[4];
int vis[10];

int sqt(int x)
{
    return x*x;
}

int in(double sx, double sy, int id)
{
    return sqt((x[id]-sx))+sqt((y[id]-sy)) <= r[id];
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    }
    for(double i = -20; i <= 20; i += 0.05){
        for(double j = -20; j <= 20; j += 0.05){
            int bit = 0;
            for(int k = 0; k < n; k++){
                if(in(i, j, k))bit += (1<<k);
            }
            vis[bit] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; i++){
        if(vis[i])ans++;
    }
    printf("%d\n", ans);
    return 0;
}

