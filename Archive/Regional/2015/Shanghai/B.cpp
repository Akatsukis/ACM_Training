#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
ll num[60];
char c[60];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        printf("Case #%d:\n", kase++);
        if(n == 1){
            ll now = 1;
            for(int i = 0; i < k; i++){
                printf("%lld %c\n", now, i == k - 1 ? '+' : '-');
                now *= 2;
            }
            continue;
        }
        else if(n == 2){
            ll now = 3;
            printf("1 -\n");
            for(int i = 1; i < k; i++){
                printf("%lld %c\n", now, i == k - 1 ? '+' : '-');
                now *= 2;
            }
            continue;
        }
        bool flag = (n%2)?0:1;
        if(flag)n--;
        n >>= 1;
        int cur = 0;
        ll now = 1;
        while(n){
            num[cur] = now;
            if(n&1)c[cur]='+';
            else c[cur]='-';
            cur++;
            now *= 2;
            n >>= 1;
        }
        if(flag)now++;
        for(int i = cur; i < k; i++){
            num[i] = now;
            c[i] = '+';
            if(i != cur)c[i-1]=(c[i-1]=='+'?'-':'+');
            now *= 2;
        }
        for(int i = 0; i < k; i++){
            printf("%lld %c\n", num[i], c[i]);
        }
    }
	return 0;
}


