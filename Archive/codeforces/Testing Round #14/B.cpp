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
    int n, a, b;
    sc(n);sc(a);sc(b);
    int p = 4, q = 2;
    int ans = 0;
    while(p || q){
        int len = 0, l = 0, r = 0;
        for(int i = 0; i <= p; i++){
            for(int j = 0; j <= q; j++){
                if(a*i+b*j <= n && a*i+b*j >= len && i+j>=l+r){
                    len = a*i+b*j;
                    l = i;
                    r = j;
                }
            }
        }
        p -= l;
        q -= r;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

