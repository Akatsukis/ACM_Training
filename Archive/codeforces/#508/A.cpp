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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
char s[maxn];
int num[26];

int main()
{
    int n, k;
    sc(n); sc(k);
    scanf("%s", s);
    for(int i = 0; i < n; i++)num[s[i]-'A']++;
    int ans = INF;
    for(int i = 0; i < k; i++)ans = min(ans, num[i]);
    printf("%d\n", ans*k);
    return 0;
}

