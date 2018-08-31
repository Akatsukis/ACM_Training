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
const int maxn = 1e6+10;
char s[maxn];
int sum[30];
int n;

bool check()
{
    for(int i = 0; i < 26; i++)if(sum[i] == 0)return 0;
    return 1;
}

int main()
{
    scanf("%s", s+1);
    n = strlen(s+1);
    int ret = INF;
    for(int l = 1, r = 1; l <= n; ){
        while(r <= n && !check()){
            sum[s[r++]-'a']++;
        }
        if(check())ret = min(ret, r-l);
        sum[s[l++]-'a']--;
    }
    printf("%d\n", ret);
    return 0;
}

