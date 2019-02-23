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
const int maxn = 20;
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)sc(a[i]);
    bool flg = 0;
    for(int i = 0; i < (1<<n); i++){
        int now = 0;
        for(int j = 0; j < n; j++){
            if(i>>j&1)now += a[j];
            else now += 360-a[j];
        }
        if(now%360 == 0)flg = 1;
    }
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}

