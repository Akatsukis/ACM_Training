#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20;
int mp[maxn][maxn];
int n, ans;

bool check(int x, int y)
{
    for(int i = x+1; i < n; i++){
        if(mp[i][y] == 1)break;
        else if(mp[i][y] == 2)return 0;
    }
    for(int i = x-1; i >= 0; i--){
        if(mp[i][y] == 1)break;
        else if(mp[i][y] == 2)return 0;
    }
    for(int i = y+1; i < n; i++){
        if(mp[x][i] == 1)break;
        else if(mp[x][i] == 2)return 0;
    }
    for(int i = y-1; i >= 0; i--){
        if(mp[x][i] == 1)break;
        else if(mp[x][i] == 2)return 0;
    }
    return 1;
}

void dfs(int x, int y, int now)
{
    //printf("dfs(%d, %d, %d)\n", x, y, now);
    //fflush(stdout);
    ans = max(ans, now);
    for(int i = x; i < n; i++){
        for(int j = i==x?y:0; j < n; j++){
            if(!mp[i][j]){
                if(check(i, j)){
                    mp[i][j] = 2;
                    dfs(i, j+1, now+1);
                    mp[i][j] = 0;
                }
                else dfs(i, j+1, now);
            }
        }
    }
}

int main()
{
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < n; j++){
                if(s[j] == '.')mp[i][j] = 0;
                else mp[i][j] = 1;
            }
        }
        ans = 0;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}

