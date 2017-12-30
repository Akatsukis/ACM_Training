#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int mp[maxn][maxn];
pii st, ed;
int ans;
int nxt[10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char ins[maxn];
int n, m;

void judge()
{
    pii now = st;
    int len = strlen(ins);
    for(int i = 0; i < len; i++){
        int nx = now.fi+dx[nxt[ins[i]-'0']], ny = now.se+dy[nxt[ins[i]-'0']];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny]){
            now = mk(nx, ny);
            if(now == ed){ans++;return;}
        }
        else return;

    }
}

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        char s[maxn];
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] != '#')mp[i][j] = 1;
            if(s[j] == 'S')st = mk(i, j);
            if(s[j] == 'E')ed = mk(i, j);
        }
    }
    scanf("%s", ins);
    for(int i = 0; i < 4; i++)nxt[i] = i;
    do{
        judge();
    }while(next_permutation(nxt, nxt+4));
    printf("%d\n", ans);
    return 0;
}

