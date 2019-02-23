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
const int maxn = 1e3+10;
int u1[maxn], u2[maxn], v1[maxn], v2[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &u1[i], &v1[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d%d", &u2[i], &v2[i]);
    }
    map<pii, int> mp;
    for(int i = 0; i < n; i++){
        set<pii> st;
        for(int j = 0; j < n; j++){
            st.insert(mk(u1[i]+u2[j], v1[i]+v2[j]));
        }
        for(auto p : st)mp[p]++;
    }
    for(auto p : mp){
        if(p.se == n){
            printf("%d %d\n", p.fi.fi, p.fi.se);
            break;
        }
    }
    return 0;
}

