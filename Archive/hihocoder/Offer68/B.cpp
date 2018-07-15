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
const ll mod = 1000000007;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
int t[maxn];

void init()
{
    for(int i = 2; i < maxn; i++){
        t[i]++;
        for(int j = i*2; j < maxn; j += i)t[j] = (t[j]+t[i])%mod;
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    printf("%d\n", t[n]);
    return 0;
}

