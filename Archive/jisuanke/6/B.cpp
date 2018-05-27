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
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
vector<int> vec;
int n, k, ans;

void dfs(vector<int> tmp, int now)
{
    vector<int> v;
    int blk = 0;
    for(int i = 1; i <= n; i++){
        int pre = tmp[i-1];
        while(i+1 <= n && tmp[i+1] == tmp[i])i++;
        if(tmp[i] > pre && tmp[i] > tmp[i+1])blk++, v.pb(i);
    }
    if(blk <= k){
        ans = min(ans, now);
        return;
    }
    for(auto u : v){
        vector<int> nxt = tmp;
        nxt[u]--;
        for(int i = u-1; i >= 1 && nxt[i] == nxt[i+1]+1; i--){
            nxt[i]--;
        }
        dfs(nxt, now+1);
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        ans = INF;
        vec.clear();
        sc(n); sc(k);
        vec.pb(0);
        for(int i = 1; i <= n; i++){
            int u; sc(u);
            vec.pb(u);
        }
        vec.pb(0);
        dfs(vec, 0);
        printf("%d\n", ans);
    }
    return 0;
}

