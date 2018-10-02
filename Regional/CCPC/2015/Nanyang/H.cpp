#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int maxn = 10;
char ans[maxn][maxn];
char s[maxn][maxn];
int stt[maxn][maxn];
int n;
bool flg;

bool check(int x, int y, int t)
{
    return (stt[0][x]&(1<<t))==0&&(stt[1][y]&(1<<t))==0&&(stt[2][(x/2)*2+(y/2)]&(1<<t)) == 0;
}

void add(int x, int y, int t)
{
    stt[0][x] += t;
    stt[1][y] += t;
    stt[2][(x/2)*2+(y/2)] += t;
}

void dfs(int x, int y)
{
    if(flg)return;
    if(x == n){
        memcpy(ans, s, sizeof(s));
        flg = 1;
        return;
    }
    int nx = y==n-1?x+1:x, ny = y==n-1?0:y+1;
    if(s[x][y] != '*')dfs(nx, ny);
    else if(s[x][y] == '*'){
        for(int i = 1; i <= 4; i++){
            if(check(x, y, i)){
                add(x, y, 1<<i);
                s[x][y] = i+'0';
                dfs(nx, ny);
                s[x][y] = '*';
                add(x, y, -(1<<i));
            }
        }
    }
}

int main()
{
    n = 4;
    int T, kase = 1; 
    scanf("%d", &T);
    while(T--){
        memset(stt, 0, sizeof(stt));
        memset(ans, 0, sizeof(ans));
        flg = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", s[i]);
            for(int j = 0; j < n; j++){
                if(s[i][j] != '*')add(i, j, 1<<(s[i][j]-'0'));
            }
        }
        dfs(0, 0);
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < n; i++)puts(ans[i]);
    }
    return 0;
}
