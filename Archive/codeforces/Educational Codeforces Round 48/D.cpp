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
const int maxn = 110;
int a[maxn];
int b[maxn];

int main()
{
    int n, m;
    sc(n); sc(m);
    int now = 0, tmp = 0;
    for(int i = 0; i < n; i++)sc(a[i]), now ^= a[i];
    for(int i = 0; i < m; i++)sc(b[i]), now ^= b[i];
    if(now)puts("NO");
    else{
        puts("YES");
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                if(!j)printf("%d%c", a[i], " \n"[j==m-1]), tmp ^= a[i];
                else printf("%d%c", 0, " \n"[j==m-1]);

            }
        }
        for(int i = 0; i < m; i++){
            if(!i)printf("%d%c", tmp^b[i], " \n"[i==m-1]);
            else printf("%d%c", b[i], " \n"[i==m-1]);
        }
    }
    return 0;
}


