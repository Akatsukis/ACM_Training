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
const int maxn = 20;
bool vis[maxn];
int tb[maxn][maxn] = {{},{1,1},{1,4,2},{1,9,18,6},{1,16,72,96,24},{1,25,200,600,600,120},{1,36,450,2400,5400,4320,720},{1,49,882,7350,29400,52920,35280,5040},{1,64,1568,18816,117600,376320,564480,322560,40320},{1,81,2592,42336,381024,1905120,5080320,6531840,3265920,362880},{1,100,4050,86400,1058400,7620480,31752000,72576000,81648000,36288000,3628800}};
int n, k;

int main()
{
    sc(n); sc(k);
    if(k <= n)printf("%d\n", tb[n][k]);
    else printf("0\n");
    return 0;
}

