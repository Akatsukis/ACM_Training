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
#include <bitset>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A,end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x"=%d\n",x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",sdtin)
#define freout freopen("out.txt","w",stdout)
#define debug cout<<"???"<<endl
#define PI 3.14159265358979323846

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5;
vector<vector<int> > G(maxn);
int deg[maxn];
bool del[maxn];
int col[maxn];
int n, k;
queue<int> q;

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(deg, 0, sizeof(deg));
        memset(del, 0, sizeof(del));
        sc(n);sc(k);
        for(int i = 1; i <= n; i++){
            G[i].clear();
            col[i] = 1;
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            sc(u);sc(v);
            G[u].pb(v);
            G[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        for(int i = 1; i <= n; i++){
            if(deg[i] == 1 && col[i] < k){
                q.push(i);
                del[i] = 1;
            }
        }
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int i = 0; i < (int)G[u].size(); i++){
                int v = G[u][i];
                if(del[v] == 1)continue;
                deg[v]--;
                col[v] += col[u];
                //printf("col[%d]=%d\n", v, col[v]);
                if(deg[v] == 1 && col[v] < k){
                    q.push(v);
                    del[v] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!del[i])ans++;
        }
        printf("%d\n", max(0, ans-1));
    }
    return 0;
}
