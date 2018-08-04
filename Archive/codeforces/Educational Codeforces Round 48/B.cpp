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
const int maxn = 1e3+10;
char s[maxn], t[maxn];
int sum[maxn];

int main()
{
    int n, m, q;
    sc(n); sc(m); sc(q);
    scanf("%s%s", s+1, t+1);
    for(int i = 1; i+m-1 <= n; i++){
        bool flg = 1;
        for(int j = 1; j <= m; j++){
            if(s[i+j-1] != t[j]){
                flg = 0;
                break;
            }
        }
        sum[i] += sum[i-1]+flg;
        //printf("sum[%d]=%d\n", i, sum[i]);
    }
    for(int i = 0; i < q; i++){
        int l, r;
        sc(l); sc(r);
        if(r-l+1 < m)printf("0\n");
        else printf("%d\n", sum[r-m+1]-sum[l-1]);
    }
    return 0;
}


