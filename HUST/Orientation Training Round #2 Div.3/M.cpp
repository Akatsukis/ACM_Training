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
#define mp make_tuple
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define tii tuple<int, int, int>
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
const int maxn = 110;
int S, M, N;
int cost[maxn][maxn][maxn];
struct tp
{
    int x, y, z;
};

int bfs()
{
    memset(cost, INF, sizeof(cost));
    cost[S][0][0] = 0;
    queue<tp> q;
    q.push(tp{S, 0, 0});
    while(q.size()){
        tp now = q.front();q.pop();
        int x = now.x, y = now.y, z = now.z;
        if((x==S/2&&y==S/2)||(x==S/2&&z==S/2)||(y==S/2&&z==S/2))return cost[now.x][now.y][now.z];
        int sum, v1, v2, v3;

        sum = now.x + now.y;
        v1 = min(S, sum);
        v2 = sum - v1;
        v3 = now.z;
        if(cost[v1][v2][v3] > cost[now.x][now.y][now.z] + 1){
            cost[v1][v2][v3] = cost[now.x][now.y][now.z] + 1;
            q.push(tp{v1, v2, v3});
        }

        sum = now.x + now.y;
        v2 = min(M, sum);
        v1 = sum - v2;
        v3 = now.z;
        if(cost[v1][v2][v3] > cost[now.x][now.y][now.z] + 1){
            cost[v1][v2][v3] = cost[now.x][now.y][now.z] + 1;
            q.push(tp{v1, v2, v3});
        }

        sum = now.x + now.z;
        v1 = min(S, sum);
        v3 = sum - v1;
        v2 = now.y;
        if(cost[v1][v2][v3] > cost[now.x][now.y][now.z] + 1){
            cost[v1][v2][v3] = cost[now.x][now.y][now.z] + 1;
            q.push(tp{v1, v2, v3});
        }

        sum = now.x + now.z;
        v3 = min(N, sum);
        v1 = sum - v3;
        v2 = now.y;
        if(cost[v1][v2][v3] > cost[now.x][now.y][now.z] + 1){
            cost[v1][v2][v3] = cost[now.x][now.y][now.z] + 1;
            q.push(tp{v1, v2, v3});
        }

        sum = now.y + now.z;
        v2 = min(M, sum);
        v3 = sum - v2;
        v1 = now.x;
        if(cost[v1][v2][v3] > cost[now.x][now.y][now.z] + 1){
            cost[v1][v2][v3] = cost[now.x][now.y][now.z] + 1;
            q.push(tp{v1, v2, v3});
        }

        sum = now.y + now.z;
        v3 = min(N, sum);
        v2 = sum - v3;
        v1 = now.x;
        if(cost[v1][v2][v3] > cost[now.x][now.y][now.z] + 1){
            cost[v1][v2][v3] = cost[now.x][now.y][now.z] + 1;
            q.push(tp{v1, v2, v3});
        }
    }
    return INF;
}

int main()
{
    while(scanf("%d%d%d", &S, &M, &N) != EOF && (S || M || N)){
        if(S & 1){
            printf("NO\n");
            continue;
        }
        int ans = bfs();
        if(ans == INF)printf("NO\n");
        else printf("%d\n", ans);
    }
    return 0;
}


