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
const int maxn = 1e5+10;
char s[maxn];
int sum[26][maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, q;
        sc(n); sc(q);
        scanf("%s", s+1);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++){
                sum[j][i] = sum[j][i-1]+(s[i]-'A'==j);
            }
        }
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < q; i++){
            int l, r;
            sc(l); sc(r);
            int ans = 0;
            for(int j = 0; j < 26; j++){
                if(sum[j][r]-sum[j][l-1]){
                    ans = sum[j][r]-sum[j][l-1];
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}


