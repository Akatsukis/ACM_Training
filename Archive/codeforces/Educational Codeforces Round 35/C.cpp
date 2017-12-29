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
const int maxn = 3e6;
bool vis[maxn];

int main()
{
    int k[3];
    scanf("%d%d%d", &k[0], &k[1], &k[2]);
    sort(k, k + 3);
    bool flag = 1;
    for(int i = 0; i < maxn; i += k[0]){
        vis[i] = 1;
    }
    for(int i = 0; i < maxn; i++){
        if(!vis[i]){
            for(int j = i; j < maxn; j += k[1]){
                vis[j] = 1;
            }
            break;
        }
    }
    for(int i = 0; i < maxn; i++){
        if(!vis[i]){
            for(int j = i; j < maxn; j += k[2]){
                vis[j] = 1;
            }
            break;
        }
    }
    for(int i = 0; i < maxn; i++){
        if(!vis[i]){
            flag = 0;
            break;
        }
    }
    if(flag)printf("YES");
    else printf("NO\n");
    return 0;
}

