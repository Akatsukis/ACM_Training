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
#define mid ((l+r)/2)
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

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100;
int n, m, k;
int mp[maxn][maxn];

struct matrix
{
    ll mat[maxn][maxn];
    void init()
    {
        memset(mat, 0, sizeof(mat));
    }
    ll det(int n)
    {
        ll res = 1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(mat[j][i] != 0){
                    for(int k = i; k < n; k++){
                        swap(mat[i][k], mat[j][k]);
                    }
                    if(i != j)res = -res;
                    break;
                }
            }
            if(mat[i][i] == 0){
                res = -1;
                break;
            }
            for(int j = i + 1; j < n; j++){
                ll mut = (mat[j][i] * mat[i][i]);
                for(int k = i; k < n; k++){
                    mat[j][k] = (mat[j][k] - (mat[i][k] * mut));
                }
            }
            res = res * mat[i][i];
        }
        return res;
    }
};

int main()
{
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j)mp[i][j] = mp[j][i] = 1;
            }
        }
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u);sc(v);
            u--;v--;
            mp[u][v] = mp[v][u] = 0;
        }
        matrix ret;
        ret.init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && mp[i][j]){
                    ret.mat[i][j] = -1;
                    ret.mat[i][i]++;
                }
            }
        }
        printf("%lld\n", ret.det(n - 1));
    }
    return 0;
}


