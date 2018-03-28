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
const int maxn = 2e6+10;
const int maxm = 70;
char s[maxn], t[maxm];
bitset<500> ans, bs[maxm];

inline int id(char c)
{
    if(c >= 'a' && c <= 'z')return c-'a';
    else if(c >= 'A' && c <= 'Z')return c-'A'+26;
    else if(c >= '0' && c <= '9')return c-'0'+52;
    else return -1;
}

int main()
{
    while(fgets(s, maxn, stdin)){
        for(int i = 0; i < maxm; i++)bs[i].set();
        ans.set();
        int len = strlen(s)-1;
        int n, k;
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%d%s", &k, t);
            for(int j = 0; j < k; j++)bs[id(t[j])].reset(i);
        }
        bool flag = 0;
        for(int i = 0; i < len; i++){
            ans <<= 1;
            int u = id(s[i]);
            if(u == -1){
                ans.set();
                continue;
            }
            ans |= bs[u];
            if(!ans[n-1]){
                flag = 1;
                printf("%d\n", i-n+2);
            }
        }
        if(!flag)puts("NULL");
        scanf(" ");
    }
    return 0;
}

