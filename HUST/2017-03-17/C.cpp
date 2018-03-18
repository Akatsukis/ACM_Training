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
const int maxn = 2e6+10;
int tree[maxn];
int n, k;

void add(int x)
{
    while(x <= n){
        tree[x] += 1;
        x += x&(-x);
    }
}

int sum(int x)
{
    int ret = 0;
    while(x){
        ret += tree[x];
        x -= x&(-x);
    }
    return ret;
}



int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(k);
        memset(tree, 0, sizeof(tree));
        ll ans = 0;
        int t;
        for(int i = 0; i < k; i++){
            sc(t);
            int ret = 0, l = 1, r = n;
            while(l <= r){
                int m = (l+r)/2;
                if(m-sum(m)>=t){
                    ret = m;
                    r = m-1;
                }
                else l = m+1;
            }
            ans += ret;
            add(ret);
        }
        printf("Case %d: %lld\n", kase++, ans);
    }
    return 0;
}
