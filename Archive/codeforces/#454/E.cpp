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
const int maxn = 22;
int G[maxn];
int v[maxn];
int res[maxn];
int ans, n, m;

void dfs(int x, int pos)
{
    bool flag = 1;
    for(int i = 0; i < n; i++){
        if(G[i] != (1<<n)-1){
            flag = 0;
            break;
        }
    }
    if(flag){
        if(x < ans){
            ans = x;
            for(int i = 0; i < x; i++)res[i] = v[i];
        }
        return;
    }
    else{
        int rec[maxn];
        for(int i = 0; i < n; i++){
            rec[i] = G[i];
        }
        flag = 0;
        for(int i = pos; i < n; i++){
            for(int j = 0; j < n; j++){
                if(G[i]&(1<<j)){
                    G[j] |= G[i];
                    if(G[j] != rec[j])flag = 1;
                }
            }
            if(flag){
                v[x] = i;
                dfs(x+1, i+1);
                for(int j = 0; j < n; j++)G[j] = rec[j];
            }
        }
    }
}

int main()
{
    srand(unsigned(time(nullptr)));
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u);sc(v);
        G[u-1] |= (1<<(v-1));
        G[v-1] |= (1<<(u-1));
    }
    for(int i = 0; i < n; i++){
        G[i] |= (1<<i);
    }
    ans = INF;
    dfs(0, 0);
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++){
        printf("%d%c", res[i]+1, i == ans-1?'\n':' ');
    }
    return 0;
}

