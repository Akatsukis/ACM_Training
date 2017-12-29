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
const int maxm = 1e6+10;
bool vis[maxm];
int sum[170][maxn];
int prime[maxn];
int a[maxn];
set<int> st;
multiset<int> mst[maxn];

void init()
{
    int num = 0;
    for(int i = 2; i < maxm; i++){
        if(!vis[i]){
            prime[num++] = i;
            for(int j = 2*i; j < maxm; j += i)vis[j] = 1;
        }
    }
}

int main()
{
    init();
    int n, m;
    sc(n);sc(m);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 170; j++){
            while(a[i]%prime[j]==0){
                sum[j][i]++;
                a[i] /= prime[j];
            }
        }
        if(a[i]>1){
            st.insert(a[i]);
            mst[i].insert(a[i]);
        }
    }
    for(int i = 0; i < 170; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] += sum[i][j-1];
            //printf("sum[%d][%d]:%d\n", i, j, sum[i][j]);
        }
        set_union(mst[i].begin(), mst[i].end(), mst[i-1].begin(), mst[i-1].end(), inserter(mst[i], mst[i].begin()));
    }
    for(int i = 0; i < m; i++){
        int l, r;
        sc(l);sc(r);
        int ans = 1;
        for(int j = 0; j < 170; j++){
            ans = 1LL*ans*(sum[j][r]-sum[j][l-1]+1)%mod;
        }
        for(auto it = st.begin(); it != st.end(); it++){
            ans = 1LL*ans*(mst[r].count(*it)-mst[l-1].count(*it)+1)%mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}

