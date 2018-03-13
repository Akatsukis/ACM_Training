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
int mp[6][6];
int prex[6][6];
int prey[6][6];
bool vis[6][6];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void print(int x, int y)
{
    if(x == 0 && y == 0){
        printf("(%d, %d)\n", x, y);
        return;
    }
    print(prex[x][y], prey[x][y]);
    printf("(%d, %d)\n", x, y);

}

int main()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            sc(mp[i][j]);
        }
    }
    queue<pii> q;
    q.push(mk(0, 0));
    vis[0][0] = 1;
    while(q.size()){
        pii tmp = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int nx = tmp.fi + dx[i], ny = tmp.se + dy[i];
            if(nx < 0 || nx > 5 || ny < 0 || ny > 5)continue;
            if(!vis[nx][ny] && !mp[nx][ny]){
                vis[nx][ny] = 1;
                q.push(mk(nx, ny));
                prex[nx][ny] = tmp.fi;
                prey[nx][ny] = tmp.se;
            }
        }
    }
    print(4, 4);
    return 0;
}


