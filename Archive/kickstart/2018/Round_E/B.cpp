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
const int maxn = 110;
int num[maxn];
char s[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(num, 0, sizeof(num));
        int n, m, p;
        set<int> ban;
        sc(n); sc(m); sc(p);
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < p; j++){
                if(s[j] == '1')num[j]++;
            }
        }
        for(int i = 0; i < m; i++){
            char s[maxn];
            scanf("%s", s);
            int now = 0;
            for(int j = 0; j < p; j++)if(s[j] == '1')now |= (1<<j);
            ban.insert(now);
        }
        int ans = INF;
        for(int i = 0; i < (1<<p); i++){
            if(ban.count(i))continue;
            int now = 0;
            for(int j = 0; j < p; j++){
                if((i>>j)&1)now += n-num[j];
                else now += num[j];
            }
            ans = min(ans, now);
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}


