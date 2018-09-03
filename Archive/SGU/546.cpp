#include <cstdio>
#include <algorithm>
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
char s[maxn];

int main()
{
    int n, a, b;
    scanf("%d%d%d%s", &n, &a, &b, s);
    int u = 0, v = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0')u++;
        if(s[i] == '1')v++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(u > a && v < b)s[i] = '1', u--, v++, ans++;
        }
        else if(s[i] == '1'){
            if(v > b && u < a)s[i] = '0', u++, v--, ans++;
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '2'){
            if(u < a)s[i] = '0', u++, ans++;
            else if(v < b)s[i] = '1', v++, ans++;
        }
        else{
            if(s[i] == '0' && u > a)s[i] = '2', u--, ans++;
            else if(s[i] == '1' && v > b)s[i] = '2', v--, ans++;
        }
    }
    if(u == a && v == b){
        printf("%d\n", ans);
        printf("%s\n", s);
    }
    else puts("-1");
    return 0;
}

