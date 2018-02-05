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
const int maxn = 3e5+10;
pii p[maxn];
priority_queue<pii> q;

bool cmp(pii a, pii b)
{
    if(a.se != b.se)return a.se < b.se;
    return a.fi < b.fi;
}

int main()
{
    int n, T;
    sc(n);sc(T);
    for(int i = 0; i < n; i++){
        sc(p[i].fi);sc(p[i].se);
    }
    sort(p, p + n, cmp);
    int now = 0, ans = 0, tme = 0;
    for(int i = 0; i < n;){
        while(i < n && q.empty() || (q.top().fi < now && tme + p[i].se <= T){
            now++;
            q.push(p[i++]);
            tme += p[i].se;
        }
        ans = max(ans, now);
        if(q.empty)
    }
    return 0;
}

