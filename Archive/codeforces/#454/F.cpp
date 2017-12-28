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

const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
int n, m;
int phi[maxn];
int a[maxn];

int get(int x)
{
    int res = x;
    for(ll i = 2; i*i <= x; i++){
        if(x%i == 0){
            res = res/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)res = res/x*(x-1);
    return res;
}

int qpow(int b, int n, int k)
{
    int res = 1;
    while(n){
        if(n&1)res=1LL*res*b>=phi[k]?1LL*res*b%phi[k]+phi[k]:res*b;
        b=1LL*b*b>=phi[k]?1LL*b*b%phi[k]+phi[k]:b*b;
        n >>= 1;
    }
    return res;
}

int solve(int l, int r, int k)
{
    //printf("l=%d r=%d k=%d\n", l, r, k);
    if(phi[k] == 1)return 1;
    if(l == r){
        if(a[l]<phi[k])return a[l];
        else return a[l]%phi[k]+phi[k];
    }
    else return qpow(a[l], solve(l+1, r, k+1), k);
}

int main()
{

    sc(n);sc(phi[0]);
    while(phi[m] != 1){
        phi[m+1] = get(phi[m]);
        //printf("phi[%d]:%d\n", m, phi[m]);
        m++;
    }
    phi[m] = 1;
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int l, r;
        sc(l);sc(r);
        int ans = solve(l, r, 0)%phi[0];
        printf("%d\n", ans);
    }
    return 0;
}


