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
const int maxn = 1e5+10;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
set<int> ban[maxn];
vector<vector<int> > pos(maxn);
vector<vector<int> > ans(maxn);
int p[maxn];

int main()
{
    int n, m;
    sc(n);sc(m);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            pos[i].pb(++cnt);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int nx = i+dx[k], ny = j+dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    ban[pos[i][j]].insert(pos[nx][ny]);
                }
            }
        }
    }
    while(clock() <= 1.9*CLOCKS_PER_SEC){
        cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i*m+j] = ++cnt;
            }
        }
        random_shuffle(p, p + n*m);
        bool flag = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i].pb(p[i*m+j]);
                for(int k = 0; k < 2; k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(ban[ans[i][j]].count(ans[nx][ny])){
                            flag = 0;
                            break;
                        }
                    }
                }
                if(!flag)break;
            }
        }
        if(flag){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    printf("%d%c", ans[i][j]+1, j == m - 1 ? '\n' : ' ');
                }
            }
            return 0;
        }

    }
    printf("NO\n");
    return 0;
}

