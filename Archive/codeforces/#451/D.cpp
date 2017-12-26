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
const int maxn = 2e6+10;
int a[maxn];

int main()
{
    int n, m, k;
    sc(n);sc(m);sc(k);
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x;
        sc(x);
        a[x]++;
        mx = max(mx, x);
    }
    int ans = 0, now = 0;
    for(int i = 1, j = 0; i <= mx && j <= mx; i++){
        while(i+m > j){
            if(now+a[j] >= k){
                ans += now+a[j]-(k-1);
                a[j] = (k-1)-now;
            }
            now += a[j++];
        }
        now -= a[i];
    }
    printf("%d\n", ans);
    return 0;
}

