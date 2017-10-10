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
const int maxn = 1e5 + 10;
ll bit0[maxn];
ll bit1[maxn];
int n, q;

void add(ll bit[], int pos, ll val)
{
    for(int i = pos; i <= n; i += (i&-i)){
        bit[i] += val;
    }
}

ll sum(ll bit[], int pos)
{
    ll res = 0;
    for(int i = pos; i; i -= (i&-i)){
        res += bit[i];
    }
    return res;
}

int main()
{
    sc(n);sc(q);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        add(bit0, i, x);
    }
//    for(int i = 1; i <= n; i++){
//        printf("bit[%d]:%lld\n", i, bit0[i]);
//    }
    for(int i = 0; i < q; i++){
        char s[2];
        scanf("%s", s);
        if(s[0] == 'C'){
            int l, r;
            ll c;
            scanf("%d%d%lld", &l, &r, &c);
            add(bit0, l, -c*(l-1));
            add(bit1, l, c);
            add(bit0, r+1, c*r);
            add(bit1, r+1, -c);
        }
        else if(s[0] == 'Q'){
            int l, r;
            scanf("%d%d", &l, &r);
            ll ans = 0;
            ans += sum(bit0, r) + sum(bit1, r)*r;
            ans -= sum(bit0, l-1) + sum(bit1, l-1)*(l-1);
            printf("%lld\n", ans);
        }
    }
	return 0;
}


