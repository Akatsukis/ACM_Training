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
const int maxn = 1e6+10;
pii p[maxn];
set<int> ans;

bool cmp(pii a, pii b)
{
    if(a.se != b.se)return a.se < b.se;
    return a.fi > b.fi;
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &p[i].fi, &p[i].se);
    }
    sort(p, p + n, cmp);
    for(int i = 0; i < n; i++){
        set<int>::iterator itl = lower_bound(ans.begin(), ans.end(), p[i].fi);
        set<int>::iterator itr = upper_bound(ans.begin(), ans.end(), p[i].se);
        int m = 2;
        while(itl != itr){
            m--;
            itl++;
        }
        for(int j = 0; j < m; j++){
            ans.insert(p[i].se - j);
        }
    }
    printf("%d\n", (int)ans.size());
    return 0;
}

