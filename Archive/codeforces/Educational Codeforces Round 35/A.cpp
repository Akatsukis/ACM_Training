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
const int maxn = 1e5+10;
int a[maxn];
vector<int> v;

int main()
{
    int n;
    sc(n);
    int mn = INF;
    for(int i = 0; i < n; i++){
        sc(a[i]);
        mn = min(a[i], mn);
    }
    for(int i = 0; i < n; i++){
        if(a[i] == mn)v.pb(i);
    }
    int ans = INF;
    for(int i = 0; i < (int)v.size()-1; i++){
        ans = min(ans, v[i+1]-v[i]);
    }
    printf("%d\n", ans);
    return 0;
}

