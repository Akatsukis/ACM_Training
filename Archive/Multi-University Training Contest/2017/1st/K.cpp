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
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
ll n, k;
int kase;

void work()
{
    if(n == 2){
        if(k&1)printf("Case #%d: %d\n", kase++, 1);
        else printf("Case #%d: %d\n", kase++, 2);
        return;
    }
    if(k <= n - 1){
        printf("Case #%d: %lld\n", kase++, k);
    }
    else{
        ll tmp = k % (n - 1);
        if(tmp != 1){
            printf("Case #%d: %lld\n", kase++, (tmp+n-2) % (n-1));
        }
        else{
            ll now = k / (n - 1);
            if(now & 1){
                printf("Case #%d: %lld\n", kase++, n);
            }
            else{
                printf("Case #%d: %lld\n", kase++, n - 1);
            }
        }
    }
}

int main()
{
    kase = 1;
    while(scanf ("%lld%lld", &n, &k) != EOF){
        work();
    }
    return 0;
}


