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
const int maxn = 220100;
char s[maxn];
char t[maxn];
int p[maxn];
int n;

int manacher()
{
    int n = strlen(s);
    t[0] = '$'; t[1] = '#';
    for(int i = 0; i < n; i++){
        t[i*2+2] = s[i];
        t[i*2+3] = '#';
    }
    int mx = -1, id = -1, ret = 1;
    for(int i = 1; i < n*2+2; i++){
        if(i < mx)p[i] = min(p[2*id-i], mx-i);
        else p[i] = 1;
        while(t[i-p[i]] == t[i+p[i]])p[i]++;
        if(i+p[i]-1 > mx){
            mx = i+p[i]-1;
            id = i;
        }
        ret = max(ret, p[i]-1);
    }
    return ret;
}

int main()
{
    while(scanf("%s", s) != EOF){
        int ans = manacher();
        printf("%d\n", ans);
    }
    return 0;
}

