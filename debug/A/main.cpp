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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, m;
const int maxn = 1e5 + 10;
vector<int> v[maxn];
vector<int> G[maxn];
int mark[maxn];
vector<int> ans;

bool dfs(int u)
{
    for(int i = 0; i < (int)G[u].size(); i++){
        int w = G[u][i];
        if(mark[w] != -1){
            if(mark[w] != mark[u])return 0;
        }
        else{
            mark[w] = mark[u];
            if(!dfs(w))return 0;
        }
    }
    return 1;
}

bool solve()
{
    memset(mark, -1, sizeof(mark));
    for(int i = 0; i < n - 1; i++){
        int sz = min(v[i].size(), v[i + 1].size()), j;
        for(j = 0; j < sz; j++){
            if(v[i][j] != v[i + 1][j])break;
        }
        if(j == sz && v[i].size() > v[i + 1].size())return 0;
    }
    for(int i = 0; i < n - 1; i++){
        int sz = min(v[i].size(), v[i + 1].size());
        for(int j = 0; j < sz; j++){
            if(v[i][j] > v[i + 1][j]){
                if(mark[v[i][j]] == 0 || mark[v[i + 1][j]] == 1)return 0;
                mark[v[i][j]] = 1;
                mark[v[i + 1][j]] = 0;
                break;
            }
            if(v[i][j] < v[i + 1][j]){
                int p = v[i][j], q = v[i + 1][j];
                G[q].pb(p);
                break;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(mark[i] == 1){
            if(!dfs(i))return 0;
        }
    }
    return 1;
}

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        int l;
        sc(l);
        for(int j = 0; j < l; j++){
            int x;
            sc(x);
            v[i].pb(x);
        }
    }
    if(solve()){
        printf("Yes\n");
        for(int i = 1; i <= m; i++){
            if(mark[i] == 1)ans.pb(i);
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < (int)ans.size(); i++){
            printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
        }
    }
    else{
        printf("No\n");
    }
	return 0;
}


