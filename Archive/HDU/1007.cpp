#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl
#define pdd pair<double,double>

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
pdd p[maxn];
vector<int> tmp;

bool cmp(int a, int b)
{
    return p[a].se < p[b].se;
}

double dist(int i, int j)
{
    double res = (p[i].fi-p[j].fi)*(p[i].fi-p[j].fi)+(p[i].se-p[j].se)*(p[i].se-p[j].se);
    return sqrt(res);
}

double solve(int l, int r)
{
    if(l == r - 1)return dist(l, r);
    if(l == r - 2){
        double v1 = dist(l, l + 1);
        double v2 = dist(l + 1, r);
        double v3 = dist(l, r);
        return min(v1, min(v2, v3));
    }
    int mid = (l + r) / 2;
    double ans = min(solve(l, mid), solve(mid + 1, r));
    tmp.clear();
    for(int i = l; i <= r; i++){
        if(fabs(p[i].fi - p[mid].fi) <= ans)tmp.pb(i);
    }
    sort(ALL(tmp), cmp);
    for(int i = 0; i < (int)tmp.size(); i++){
        for(int j = i + 1; j < (int)tmp.size(); j++){
            if(p[tmp[j]].se - p[tmp[i]].se >= ans)break;
            ans = min(ans, dist(tmp[i], tmp[j]));
        }
    }
    return ans;
}

int main()
{
    int n;
    while(sc(n) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%lf%lf", &p[i].fi, &p[i].se);
        }
        sort(p, p + n);
        double ans = solve(0, n - 1);
        printf("%.2f\n", ans / 2);
    }
    return 0;
}
