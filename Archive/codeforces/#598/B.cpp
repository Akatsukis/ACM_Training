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
const int maxn = 1e2+10;
int pos[maxn], a[maxn];;
bool vis[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
            vis[i] = 0;
        }
        vis[0] = 1;
        for(int i = 1; i <= n; i++) {
            while(!vis[pos[i]-1]) {
                vis[pos[i]-1] = 1;
                int x = i, y = a[pos[i]-1];
                swap(a[pos[i]], a[pos[i]-1]);
                pos[x]--, pos[y]++;
                
            }
            vis[pos[i]] = 1;
        }
        for(int i = 1; i <= n; i++) {
            printf("%d%c", a[i], " \n"[i==n]);
        }
    }
    return 0;
}

