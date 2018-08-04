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
const int maxn = 100;
int b[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++)scanf("%*d%d", &b[i]);
        sort(b, b+n);
        int ans = 0;
        ll cnt = 1;
        for(int i = 0; i < n; i++){
            cnt *= (b[i]+1);
            if(cnt > m)break;
            else ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}


