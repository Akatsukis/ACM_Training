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
const int maxn = 5e6+10;
bitset<1000> ans, bs[10];
char s[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        int k, t;
        sc(k);
        for(int j = 0; j < k; j++){
            sc(t);
            bs[t].set(i);
        }
    }
    scanf(" ");
    fgets(s, maxn, stdin);
    int len = strlen(s)-1;
    for(int i = 0; i < len; i++){
        ans <<= 1;
        ans.set(0);
        ans &= bs[s[i]-'0'];
        if(ans[n-1]){
            char ch = s[i+1];
            s[i+1] = 0;
            puts(s+i-n+1);
            s[i+1] = ch;
        }
    }
    return 0;
}

