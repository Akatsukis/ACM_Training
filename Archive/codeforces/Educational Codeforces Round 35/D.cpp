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
const int maxn = 1500+10;
int n;
int a[maxn];

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i] > a[j])cnt++;
        }
    }
    bool flag=cnt&1;
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int l, r;
        sc(l);sc(r);
        ll k = r-l+1;
        if(k*(k-1)/2%2==1)flag = !flag;
        if(flag)printf("odd\n");
        else printf("even\n");
    }
    return 0;
}

