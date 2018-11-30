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
vector<int> vec[maxn];
int val[maxn];

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < n; i++){
        int s, r;
        sc(s); sc(r);
        vec[s].pb(r);
    }
    for(int i = 0; i < maxn; i++)sort(ALL(vec[i]), greater<int>());
    for(int i = 0; i < maxn; i++){
        int sum = 0, num = 0;
        for(auto v : vec[i]){
            sum += v; num++;
            val[num] += max(sum, 0);
        }
    }
    int ans = 0;
    for(int i = 0; i < maxn; i++)ans = max(ans, val[i]);
    printf("%d\n", ans);
    return 0;
}

