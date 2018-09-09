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
const int maxn = 20;
vector<int> vec[maxn];

int main()
{
    int n, q;
    sc(n); sc(q);
    for(int i = 0; i < n; i++){
        int m; sc(m);
        for(int j = 0; j < m; j++){
            int x; sc(x);
            vec[i].pb(x);
        }
    }
    for(int i = 0; i < q; i++){
        int m; sc(m);
        vector<int> in;
        for(int j = 0; j < m; j++){
            int x; sc(x);
            in.pb(x);
        }
        vector<vector<int> > ans;
        for(int j = 0; j < n; j++){
            bool ok = 1;
            for(auto u : in){
                bool flg = u<0;
                for(auto v : vec[j]){
                    if(u > 0 && u == v){
                        flg = 1;
                        break;
                    }
                    if(u < 0 && -u == v){
                        flg = 0;
                        break;
                    }
                }
                if(!flg){
                    ok = 0;
                    break;
                }
            }
            if(ok)ans.pb(vec[j]);
        }
        printf("%d\n", SZ(ans));
        for(auto vec : ans){
            printf("%d ", SZ(vec));
            for(int j = 0; j < SZ(vec); j++){
                printf("%d%c", vec[j], " \n"[j==SZ(vec)-1]);
            }
        }
    }
    return 0;
}

