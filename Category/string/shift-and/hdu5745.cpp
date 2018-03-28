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
const int maxn = 1e5+10;
const int maxm = 5000+10;
char s[maxn], t[maxm];
bitset<maxn> bs[27], ans[2][2];

int main()
{
    int T;
    sc(T);
    while(T--){
        int len, n;
        scanf("%d%d", &len, &n);
        scanf("%s%s", s+1, t+1);
        t[0] = t[n+1] = 'z'+1;
        for(int i = 0; i <= 26; i++)bs[i].reset();
        for(int i = 1; i <= len; i++)bs[s[i]-'a'].set(i);
        int cnt = 0, pre = 1;
        ans[pre][0].set(), ans[pre][1].reset();
        for(int i = 1; i <= n; i++){
            ans[cnt][0] = ((ans[pre][0]<<1)&bs[t[i]-'a'])|((ans[pre][1]<<1)&bs[t[i-1]-'a']);
            ans[cnt][1] = ((ans[pre][0]<<1)&bs[t[i+1]-'a']);
            swap(cnt, pre);
        }
        for(int i = 1; i <= len; i++){
            if(i+n-1 <= len && (ans[pre][0][i+n-1]|ans[pre][1][i+n-1]))putchar('1');
            else putchar('0');
        }
        puts("");
    }
    return 0;
}

