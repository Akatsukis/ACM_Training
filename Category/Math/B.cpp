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
const int maxn = 50010;
int euler[maxn];
int pre[maxn];

void init()
{
    for(int i = 0; i < maxn; i++)euler[i] = i;
    for(int i = 2; i < maxn; i++){
        if(euler[i] == i){
            for(int j = i; j < maxn; j += i)euler[j] = euler[j]/i*(i-1);
        }
    }
    pre[1] = 1;
    for(int i = 2; i < maxn; i++)pre[i] = pre[i-1]+euler[i]*2;
}

int main()
{
    init();
    int n;
    while(sc(n) != EOF && n){
        printf("%d\n", pre[n]);
    }
    return 0;
}

