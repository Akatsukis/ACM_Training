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
const int maxn = 2e5+10;
bool vis[maxn];
deque<int> sk;


int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        int x; sc(x);
        sk.pb(x);
    }
    for(int i = 0; i < n; i++){
        int x; sc(x);
        int ans = 0;
        while(!vis[x]){
            int y = sk.front(); sk.pop_front();
            vis[y] = 1;
            ans++;
        }
        printf("%d%c", ans, " \n"[i==n-1]);
    }
    return 0;
}

