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
const int maxn = 1000100;
int s[maxn];
int t[maxn];
int nxt[maxn];
int n, m;

void get_next()
{
    int k = 0;
    for(int i = 1; i < m; i++){
        while(k && t[i] != t[k])k = nxt[k-1];
        if(t[i] == t[k])k++;
        nxt[i] = k;
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n); sc(m);
        for(int i = 0; i < n; i++)sc(s[i]);
        for(int i = 0; i < m; i++)sc(t[i]);
        get_next();
        int ans = -1;
        int k = 0;
        for(int i = 0; i < n; i++){
            while(k && s[i] != t[k])k = nxt[k-1];
            if(s[i] == t[k])k++;
            if(k == m){
                ans = i-m+2;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
