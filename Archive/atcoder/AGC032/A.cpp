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
const int maxn = 1e2+10;

int main()
{
    int n;
    sc(n);
    list<int> b(n, 0);
    for(auto &u : b)sc(u);
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        int val = 1, res = 0;
        auto tmp = b.begin();
        for(auto it = b.begin(); it != b.end(); it++){
            int u = *it;
            if(u == val)res = val, tmp = it;
            val++;
        }
        if(!res){
            printf("-1\n");
            return 0;
        }
        else ans.pb(res), b.erase(tmp);
    }
    reverse(ans.begin(), ans.end());
    for(auto u : ans)printf("%d\n", u);
    return 0;
}

