#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 1e5+10;
int a[maxn], num[maxn][2];

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int x; sc(x);
        num[x][i%2]++;
    }
    vector<pii> vec[2];
    for(int i = 0; i < maxn; i++){
        vec[0].pb(mk(num[i][0], i));
        vec[1].pb(mk(num[i][1], i));
    }
    sort(ALL(vec[0]), greater<pii>());
    sort(ALL(vec[1]), greater<pii>());
    int ans = 0;
    for(int i = 0; i < 2 && i < SZ(vec[0]); i++){
        for(int j = 0; j < 2 && j < SZ(vec[1]); j++){
            if(vec[0][i].se == vec[1][j].se)continue;
            else ans = max(ans, vec[0][i].fi+vec[1][j].fi);
        }
    }
    printf("%d\n", n-ans);
    return 0;
}

