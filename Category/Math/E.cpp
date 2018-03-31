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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 30+10;
int a[maxn];
int b[maxn];
int mat[maxn][maxn];

int Gauss(int n)
{
    int ret = 0, c = 0, r = 0;
    for(; c < n && r < n; c++, r++){
        int k = r;
        for(int j = k+1; j < n; j++){
            if(mat[j][c] != 0){
                k = j;
                break;
            }
        }
        if(!mat[k][c]){
            r--;
            continue;    
        }
        if(k != r){
            for(int j = c; j < n+1; j++)swap(mat[r][j], mat[k][j]);
        }
        for(int i = r+1; i < n; i++){
            if(mat[i][c]){
                for(int j = c; j < n+1; j++)mat[i][j] ^= mat[r][j];
            }
        }
    }
    for(int i = r; i < n; i++){
        if(mat[i][n])return -1;
    }
    ret = n-r;
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(mat, 0, sizeof(mat));
        int n;
        sc(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        for(int i = 0; i < n; i++)sc(b[i]);
        int u, v;
        while(scanf("%d%d", &u, &v) && (u||v)){
            mat[v-1][u-1] = 1; 
        }
        for(int i = 0; i < n; i++)mat[i][n] = a[i]^b[i], mat[i][i] = 1;
        int ans = Gauss(n);
        if(ans == -1)printf("Oh,it's impossible~!!\n");
        else printf("%d\n", 1<<ans);
    }
    return 0;
}

