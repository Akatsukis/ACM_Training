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
const int maxn = 1e5+10;
int p[maxn], h[maxn], x[maxn], y[maxn];
int A[5], B[5], C[5], M[5];
struct atom
{
    int x, y, id;
    bool operator < (const atom &rhs)const
    {
        if(x != rhs.x)return x < rhs.x;
        else return y < rhs.y;
    }
}bal[maxn], tow[maxn];
bool vis[maxn];


int main()
{
    int T, kase = 1; 
    sc(T);
    while(T--){
        memset(vis, 0, sizeof(vis));
        int N, K;
        scanf("%d%d", &N, &K);
        scanf("%d%d%d%d%d%d", &p[1], &p[2], &A[1], &B[1], &C[1], &M[1]);
        scanf("%d%d%d%d%d%d", &h[1], &h[2], &A[2], &B[2], &C[2], &M[2]);
        scanf("%d%d%d%d%d%d", &x[1], &x[2], &A[3], &B[3], &C[3], &M[3]);
        scanf("%d%d%d%d%d%d", &y[1], &y[2], &A[4], &B[4], &C[4], &M[4]);
        for(int i = 3; i <= N; i++){
            p[i] = (1LL*A[1]*p[i-1]+1LL*B[1]*p[i-2]+C[1])%M[1]+1;
            h[i] = (1LL*A[2]*h[i-1]+1LL*B[2]*h[i-2]+C[2])%M[2]+1;
        }
        for(int i = 3; i <= K; i++){
            x[i] = (1LL*A[3]*x[i-1]+1LL*B[3]*x[i-2]+C[3])%M[3]+1;
            y[i] = (1LL*A[4]*y[i-1]+1LL*B[4]*y[i-2]+C[4])%M[4]+1;
        }
        int ans = 0;
        for(int i = 1; i <= K; i++){
            bal[i] = atom{x[i], y[i]};
        }
        for(int i = 1; i <= N; i++){
            tow[i] = atom{p[i], h[i]};
        }
        sort(bal+1, bal+1+K);
        sort(tow+1, tow+1+N);
        int cnt = 1;
        set<pii> st;
        for(int i = 1; i <= N; i++){
            while(cnt <= K && tow[i].x >= bal[cnt].x){
                st.insert(mk(bal[cnt].y-bal[cnt].x, cnt));
                cnt++;
            }
            auto it = st.lower_bound(mk(tow[i].y-tow[i].x, 0));
            while(it != st.end()){
                vis[it->se] = 1;
                st.erase(it++);
            }
        }
        st.clear();
        cnt = K;
        for(int i = N; i >= 1; i--){
            while(cnt && tow[i].x <= bal[cnt].x){
                st.insert(mk(bal[cnt].y+bal[cnt].x, cnt));
                cnt--;
            }
            auto itr = st.upper_bound(mk(tow[i].x+tow[i].y, 0));
            auto itl = st.begin();
            while(itl != itr){
                vis[itl->se] = 1;
                st.erase(itl++);
            }
        }
        for(int i = 1; i <= K; i++)if(vis[i])ans++;
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}


