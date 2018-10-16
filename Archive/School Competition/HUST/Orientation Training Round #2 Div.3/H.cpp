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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int cost[maxn][maxn];
int prex[maxn][maxn];
int prey[maxn][maxn];
int pret[maxn][maxn];
int V[3];
char s[6][20]{"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(2,1)", "POUR(1,2)"};

void print(int x, int y)
{
    if(x == 0 && y == 0)return;
    print(prex[x][y], prey[x][y]);
    printf("%s\n", s[pret[x][y]]);
}

pii bfs()
{
    memset(cost, INF, sizeof(cost));
    queue<pii> q;
    q.push(mk(0, 0));
    cost[0][0] = 0;
    while(q.size()){
        pii now = q.front();q.pop();
        if(now.fi == V[2] || now.se == V[2])return mk(now.fi, now.se);
        if(cost[V[0]][now.se] > cost[now.fi][now.se] + 1){
            cost[V[0]][now.se] = cost[now.fi][now.se] + 1;
            q.push(mk(V[0], now.se));
            prex[V[0]][now.se] = now.fi;
            prey[V[0]][now.se] = now.se;
            pret[V[0]][now.se] = 0;
        }
        if(cost[now.fi][V[1]] > cost[now.fi][now.se] + 1){
            cost[now.fi][V[1]] = cost[now.fi][now.se] + 1;
            q.push(mk(now.fi, V[1]));
            prex[now.fi][V[1]] = now.fi;
            prey[now.fi][V[1]] = now.se;
            pret[now.fi][V[1]] = 1;
        }
        if(cost[0][now.se] > cost[now.fi][now.se] + 1){
            cost[0][now.se] = cost[now.fi][now.se] + 1;
            q.push(mk(0, now.se));
            prex[0][now.se] = now.fi;
            prey[0][now.se] = now.se;
            pret[0][now.se] = 2;
        }
        if(cost[now.fi][0] > cost[now.fi][now.se] + 1){
            cost[now.fi][0] = cost[now.fi][now.se] + 1;
            q.push(mk(now.fi, 0));
            prex[now.fi][0] = now.fi;
            prey[now.fi][0] = now.se;
            pret[now.fi][0] = 3;
        }
        int sum = now.fi + now.se;
        int v1, v2;
        v1 = min(V[0], sum);
        v2 = sum - v1;
        if(cost[v1][v2] > cost[now.fi][now.se] + 1){
            cost[v1][v2] = cost[now.fi][now.se] + 1;
            q.push(mk(v1, v2));
            prex[v1][v2] = now.fi;
            prey[v1][v2] = now.se;
            pret[v1][v2] = 4;
        }
        v2 = min(V[1], sum);
        v1 = sum - v2;
        if(cost[v1][v2] > cost[now.fi][now.se] + 1){
            cost[v1][v2] = cost[now.fi][now.se] + 1;
            q.push(mk(v1, v2));
            prex[v1][v2] = now.fi;
            prey[v1][v2] = now.se;
            pret[v1][v2] = 5;
        }
    }
    return mk(maxn - 1, maxn - 1);
}

int main()
{
    for(int i = 0; i < 3; i++){
        sc(V[i]);
    }
    pii ans = bfs();
    if(cost[ans.fi][ans.se] != INF){
        printf("%d\n", cost[ans.fi][ans.se]);
        print(ans.fi, ans.se);
    }
    else printf("impossible\n");
    return 0;
}


