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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
int mp[maxn][maxn];
int cost[maxn][maxn];
int qlx, qrx;
int qly, qry;

void update(int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nx = x+i, ny = y+j;
            if(nx >= qlx && nx <= qrx && ny >= qly && ny <= qry){
                cost[nx][ny]--;
            }
        }
    }
}

void get()
{
    vector<pii> ret[10];
    for(int i = qlx; i <= qrx; i++){
        for(int j = qly; j <= qry; j++){
            ret[cost[i][j]].pb(mk(i, j));
        }
    }
    for(int i = 9; i >= 1; i--){
        if(ret[i].size()){
            int p = rand()%ret[i].size();
            printf("%d %d\n", ret[i][p].fi, ret[i][p].se);
            fflush(stdout);
            return;
        }
    }
}

bool solve()
{
    int nx, ny;
    while(1){
        get();
        scanf("%d%d", &nx, &ny);
        if(nx == 0 && ny == 0)return 1;
        if(nx == -1 && ny == -1)return 0;
        if(!mp[nx][ny]){
            mp[nx][ny] = 1;
            update(nx, ny);
        }
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    int T;
    sc(T);
    while(T--){
        int A;
        sc(A);
        qlx = qly = 2;
        for(qrx = 2; (qrx+1)*(qrx+1) < A; qrx++);
        qry = qrx;
        int k = rand()%950;
        qlx += k, qrx += k;
        k = rand()%950;
        qly += k, qry += k;
        for(int i = qlx; i <= qrx; i++){
            for(int j = qly; j <= qry; j++){
                cost[i][j] = 9;
            }
        }
        if(!solve())return 0;
    }
    return 0;
}

