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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int nxt[maxn], pre[maxn];
int n, k, cnt;

void del(int x)
{
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

int main()
{
    sc(n); sc(k);
    for(int i = 1; i <= n; i++){
        pre[i] = i-1;
        nxt[i] = i+1;
    }
    pre[1] = n, nxt[n] = 1;
    int u = 1;
    while(nxt[u] != u){
        cnt++;
        int v = nxt[u];
        if(cnt%k==0||cnt%10==k)del(u);
        u = v;
    }
    printf("%d\n", u);
    return 0;
}

