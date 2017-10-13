#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1000 + 10;
int a[maxn];
int b[maxn];

int solve(int k, int al, int ar, int bl, int br)
{
    printf("k=%d al=%d ar=%d bl=%d br=%d\n", k, al, ar, bl, br);
    int Len_a = ar - al + 1;
    int Len_b = br - bl + 1;
    if(Len_a == 0)return b[bl + k];
    if(Len_b == 0)return a[al + k];
    if(k == 0)return a[al] < b[bl] ? a[al] : b[bl];
    int am = Len_a * k / (Len_a + Len_b);
    int bm = Len_b * k / (Len_a + Len_b);
    printf("am=%d bm=%d\n", am, bm);
    am += al;
    bm += bl;
    if(a[am] > b[bm]){
        k = k - (bm - bl + 1);
        ar = am;
        bl = bm + 1;
    }
    else{
        k = k - (am - al + 1);
        br = bm;
        al = am + 1;
    }
    return solve(k, al, ar, bl, br);
}

int main()
{
    frein;
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
    }
    int ans = solve(n, 0, n - 1, 0, n - 1);
    printf("%d\n", ans);
	return 0;
}


