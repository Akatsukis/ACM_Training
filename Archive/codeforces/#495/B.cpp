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
const int maxn = 1e3+10;
int n, m;
pii p[maxn];

int main()
{
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &p[i].fi, &p[i].se);
    }
    for(int i = 0; i < n; i++){
        if(i%2==0)putchar('1');
        else putchar('0');
    }
    return 0;
}

