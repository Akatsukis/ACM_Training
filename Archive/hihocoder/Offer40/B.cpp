#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int T;
    sc(T);
    while(T--){
        ull x, k;
        scanf("%llu%llu", &x, &k);
        ull now = 1;
        ull i = x;
        int j = 0;
        while(now != k && j < 100 && i >= 3){
            now *= i%10;
            now %= 10;
            i -= 2;
            j++;
        }
        if(i >= 1 && now == k)printf("%llu\n", i);
        else printf("-1\n");
    }
    return 0;
}

