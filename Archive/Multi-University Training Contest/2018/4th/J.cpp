#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 18;
int mat[maxn][maxn];
bool vr[maxn][maxn], vc[maxn][maxn];
int ans;

bool check(int x, int y)
{
    for(int i = x; i < x+4; i++){
        for(int j = y; j < y+4; j++){
            if(vr[i][mat[i][j]])return 0;
            if(vc[j][mat[i][j]])return 0;
        }
    }
    return 1;
}

void add(int x, int y, int v)
{
    for(int i = x; i < x+4; i++){
        for(int j = y; j < y+4; j++){
            vr[i][mat[i][j]] = v;
            vc[j][mat[i][j]] = v;
        }
    }
}

void rotate(int x, int y)
{
    int tmp[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            tmp[i][j] = mat[x+3-j][y+i];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            mat[x+i][y+j] = tmp[i][j];
        }
    }
}

void dfs(int now, int x, int y)
{
    if(now >= ans)return;
    if(x == 16){
        ans = now;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = y==12?x+4:x, ny = y==12?0:y+4;
        if(check(x, y)){
            add(x, y, 1);
            dfs(now+i, nx, ny);
            add(x, y, 0);
        }
        rotate(x, y);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        for(int i = 0; i < 16; i++){
            char s[20];
            scanf("%s", s);
            for(int j = 0; j < 16; j++){
                if(isdigit(s[j]))mat[i][j] = s[j]-'0';
                else mat[i][j] = s[j]-'A'+10;
            }
        }
        ans = 50;;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}


