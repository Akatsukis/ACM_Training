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
char s[maxn];
int sum[maxn];

int main()
{
    int n;
    scanf("%d%s", &n, s+1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1]+s[i]-'0';
    }
    int tot = sum[n];
    if(!tot){
        puts("YES");
        return 0;
    }
    for(int i = 2; i <= tot; i++){
        if(tot%i)continue;
        int seg = tot/i, t = 1;
        bool flg = 1;
        for(int j = 1; j <= n; j++){
            if(sum[j] > t*seg){
                flg = 0;
                break;
            }
            else if(sum[j] == t*seg)t++;
        }
        if(flg){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}

