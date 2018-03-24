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
char s[maxn];
int nxt[maxn];
int n;

int mstring(int t)
{
    int i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n){
        if(s[(i+k)%n] == s[(j+k)%n])k++;
        else{
            if(s[(i+k)%n] > s[(j+k)%n]){
                if(t == 0)i += k+1;
                else j += k+1;
            }
            else{
                if(t == 0)j += k+1;
                else i += k+1;
            }
            if(i == j)j++;
            k = 0;
        }
    }
    return min(i, j);
}

int get_next()
{
    int k = 0;
    for(int i = 1; i < n; i++){
        while(k && s[i] != s[k])k = nxt[k-1];
        if(s[i] == s[k])k++;
        nxt[i] = k;
    }
    int ret = 1;
    for(int i = n-1; i > 0; i--){
        if(nxt[i] == 1){
            return n%(n-nxt[n-1])?1:n/(n-nxt[n-1]);
        }
        if(nxt[i] != nxt[i-1]+1)return 1;
    }
    return ret;
}

int main()
{
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        int ans1 = mstring(0), ans2 = mstring(1);
        int t = get_next();
        printf("%d %d %d %d\n", ans1+1, t, ans2+1, t);
    }
    return 0;
}

