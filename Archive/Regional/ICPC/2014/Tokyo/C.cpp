#include <cstdio>
#include <iostream>
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
#include <bitset>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define PI 3.14159265358979323846
#define debug cout<<"???"<<endl;

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

const int maxn = 1e3+100;

int vis[maxn], n, m;
int main()
{
    while(cin >> n >> m){
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < m; i++){
            int u,v;
            sc(v); sc(u);
            for(int i = u-1; i >= v; i--){
                vis[i] = 1;
            }
        }
        int ans = n+1;
        for(int i = 0; i <= n; i++) ans += 2*vis[i];
        printf("%d\n", ans);
    }
    return 0;
}
