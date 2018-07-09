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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        sc(n);
        for(int i = 0; i <= n; i++)scanf("%*d");
        if(n&1)printf("Case #%d: 1\n0.0\n", kase++);
        else printf("Case #%d: 0\n", kase++);
    }
    return 0;
}

