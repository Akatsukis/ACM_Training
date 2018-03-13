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
const int maxn = 40;
int mp[40][40][40];
int cost[40][40][40];
int L, R, C;
struct node
{
    int x, y, z;
}st, ed;
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int bfs()
{
    queue<node> q;
    q.push(st);
    memset(cost, INF, sizeof(cost));
    cost[st.x][st.y][st.z] = 0;
    while(q.size()){
        node tmp = q.front();q.pop();
        for(int i = 0; i < 6; i++){
            int nx = tmp.x + dx[i], ny = tmp.y + dy[i], nz = tmp.z + dz[i];
            if(nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)continue;
            if(mp[nx][ny][nz] && cost[nx][ny][nz] > cost[tmp.x][tmp.y][tmp.z] + 1){
                cost[nx][ny][nz] = cost[tmp.x][tmp.y][tmp.z] + 1;
                //printf("cost[%d][%d][%d]:%d->cost[%d][%d][%d]:%d\n", tmp.x, tmp.y, tmp.z, cost[tmp.x][tmp.y][tmp.z], nx, ny, nz, cost[nx][ny][nz]);
                node nxt;
                nxt.x = nx, nxt.y = ny, nxt.z = nz;
                q.push(nxt);
            }
        }
    }
    return cost[ed.x][ed.y][ed.z];
}

int main()
{
    while(scanf("%d%d%d", &L, &R, &C) != EOF && L){
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                char s[40];
                scanf("%s", s);
                for(int k = 0; k < C; k++){
                    if(s[k] == '#')mp[i][j][k] = 0;
                    else mp[i][j][k] = 1;
                    if(s[k] == 'S'){
                        st.x = i, st.y = j, st.z = k;
                    }
                    if(s[k] == 'E'){
                        ed.x = i, ed.y = j, ed.z = k;
                    }
                }
            }
        }
        int ans = bfs();
        if(ans == INF)printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}


