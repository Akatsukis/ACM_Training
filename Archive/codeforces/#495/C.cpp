#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
bool vis[maxn];
int last[maxn];
int a[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!last[a[i]])cnt++;
        last[a[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(last[a[i]] == i)cnt--;
        if(vis[a[i]])continue;
        else vis[a[i]] = 1;
        ans += cnt;
    }
    printf("%lld\n", ans);
    return 0;
}

