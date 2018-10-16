#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ALL(A) A.begin(),A.end()
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n", x)
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 10;
int p[maxn], q[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        for(int i = 1; i <= 3; i++){
            scanf("%d%d", &p[i], &q[i]);
        }
        bool flag1 = 0, flag2 = 0;
        int cnt = 0;
        for(int i = 1; i <= 3; i++){
            if(p[i]*2<p[i]+q[i])flag1 = 1;
            else if(p[i]*2>p[i]+q[i])flag2 = 1;
            else cnt++;
        }
        if((flag1==1&&flag2==1)||cnt==3)printf("Case %d: Yes\n", kase++);
        else printf("Case %d: No\n", kase++);
    }
    return 0;
}
