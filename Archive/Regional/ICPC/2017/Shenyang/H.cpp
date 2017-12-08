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
#define prt(x) printf(#x"=%f\n",x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",sdtin)
#define freout freopen("out.txt","w",stdout)
#define debug cout<<"???"<<endl
#define PI 3.14159265358979323846

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxh = 41;

int sgn(double x){
    if ( x > eps ) return 1;
    else if (x < -eps) return -1;
    else return 0;
}

int cmp(double a, double b)
{
    return sgn(a-b);
}

const int dh[4][3][4] = {
    {{0,-1,0,0},{0,0,0,0},{0,0,0,-1}},
    {{-1,0,0,0},{0,0,-1,0},{0,0,0,-1}},
    {{0,0,0,0},{0,-1,0,0},{0,0,0,-1}},
    {{-1,0,0,0},{0,-1,0,0},{0,0,-1,0}}};

int vis[maxh][maxh][maxh][maxh][4];
double dp[maxh][maxh][maxh][maxh][4][2];

///攻击顺序：主反忠内   ， 给出顺序：主忠反内
void solve(int h1, int h2, int h3, int h4, int r)
{/// p == 0 主忠  p == 1 反


    double &ans0 = dp[h1][h2][h3][h4][r][0]; double &ans1 = dp[h1][h2][h3][h4][r][1];
    //printf("solve(%d, %d, %d, %d, %d)\n", h1,h2,h3,h4,r);
    if(vis[h1][h2][h3][h4][r]){
        //prt(ans0); prt(ans1);
        return;
    }

    if(h1 == 0 && (h2 > 0 || h3 > 0)){
        //pr(1);
        ans0 = 0; ans1 = 1;
        return;
    }
    if(h2 == 0 && h4 == 0 && h1 > 0){
        //pr(2);
        ans0 = 1; ans1 = 0;
        return;
    }
    if(h1 == 0 && h2 == 0 && h3 == 0 && h4 > 0){
        //pr(3);
        ans0 = 0; ans1 = 0;
        return;
    }
    //pr(4);
    vis[h1][h2][h3][h4][r] = 1;
    int idx = 0, nxt[4], now[4] = {h1,h2,h3,h4};
    double mx = -1, tmp = 0;

    if(now[r] == 0){
        solve(h1,h2,h3,h4,(r+1)%4);
        ans0 = dp[h1][h2][h3][h4][(r+1)%4][0];
        ans1 = dp[h1][h2][h3][h4][(r+1)%4][1];
        return;
    }

    for(int i = 0; i < 3; i++){
        int flg = 1;
        if(r == 0 && i == 1) continue;
        if(r == 2 && i == 0) continue;
        for(int j = 0; j < 4; j++){
            nxt[j] = now[j]+dh[r][i][j];
            if(nxt[j] < 0) flg = 0;
        }
        if(flg == 0) continue;
        //printf("solve(%d, %d, %d, %d, %d) --> solve(%d, %d, %d, %d, %d)\n",
         //       h1,h2,h3,h4,r,nxt[0],nxt[1],nxt[2],nxt[3],(r+1)%4);

        solve(nxt[0],nxt[1],nxt[2],nxt[3],(r+1)%4);
        double win_zhu = dp[nxt[0]][nxt[1]][nxt[2]][nxt[3]][(r+1)%4][0],
            win_fan = dp[nxt[0]][nxt[1]][nxt[2]][nxt[3]][(r+1)%4][1],
            win_nei = 1-win_zhu-win_fan;

        if(r == 0 || r == 2){
            if(cmp(win_zhu, mx) == 1){
                idx = 1;
                mx = win_zhu;
                tmp = win_fan;
                //printf("mx:%f, tmp:%f\n", mx, tmp);
            }else if(cmp(win_zhu, mx) == 0){
                tmp += win_fan; idx++;
            }
        }else if(r == 1){
            if(cmp(win_fan, mx) == 1){
                idx = 1;
                mx = win_fan;
                tmp = win_zhu;
            }else if(cmp(win_fan, mx) == 0){
                tmp += win_zhu; idx++;
            }
        }else{
            if(cmp(win_nei, mx) == 1){
                idx = 1;
                mx = win_nei;
                tmp = win_fan;
            }else if(cmp(win_nei, mx) == 0){
                tmp += win_fan; idx++;
            }
        }
    }

    //printf("solve(%d, %d, %d, %d, %d): mx:%f, tmp:%f, idx:%d\n", h1,h2,h3,h4,r,mx,tmp,idx);
    if(r == 0 || r == 2){
        ans0 = mx;
        ans1 = tmp/idx;
        //printf("ans0:%f, ans1:%f\n",ans0,ans1);
    }else if(r == 1){
        ans1 = mx;
        ans0 = tmp/idx;
        //printf("ans0:%f, ans1:%f\n",ans0,ans1);
    }else{
        ans1 = tmp/idx;
        ans0 = 1-ans1-mx;
        //printf("ans0:%f, ans1:%f\n",ans0,ans1);
    }
}

int main()
{
    //freout;
    int T; sc(T);
    memset(vis, 0, sizeof(vis));
    while(T--){
        int h1,h2,h3,h4; sc(h1); sc(h2); sc(h3); sc(h4);
        solve(h1,h3,h2,h4,0);
        double ans0 = dp[h1][h3][h2][h4][0][0],
                ans1 = dp[h1][h3][h2][h4][0][1],
                ans2 = 1-ans0-ans1;
        printf("%.6f %.6f %.6f\n", ans0, ans1, ans2);
    }
    return 0;
}
