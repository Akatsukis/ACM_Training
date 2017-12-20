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
pii a[1000];
int vis[1000];

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        sc(a[i].fi);
        sc(a[i].se);
    }
    sort(a, a + n);
    vis[0] = 1;
    for(int i = 0; i < n; i++){
        if(vis[a[i].fi]){
            for(int j = a[i].fi; j <= a[i].se; j++){
                vis[j] = 1;
            }
        }
    }
    if(vis[m])printf("YES\n");
    else printf("NO\n");
    return 0;
}

