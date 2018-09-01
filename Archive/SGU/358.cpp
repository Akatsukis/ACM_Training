#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
int a[3], b[3];

int main()
{
    int n = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)sc(a[j]);
        sort(a, a+n);
        b[i] = a[1];
    }
    sort(b, b+n);
    printf("%d\n", b[1]);
    return 0;
}

