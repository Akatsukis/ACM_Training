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
#include <ctime>
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
const int maxn = 2500 + 10;

ll tree[maxn][maxn];

ll Hash(int r1, int c1, int r2, int c2)
{
    ll res = r1;
    res = res*maxn+c1;
    res = res*maxn+r2;
    res = res*maxn+c2;
    return res;
}

void add(int x, int y, int n, int m, ll val)
{
    for(int i = x; i <= n; i += (i&-i)){
        for(int j = y; j <= m; j += (j&-j)){
            tree[i][j] += val;
        }
    }
}

ll query(int x, int y)
{
    ll ans = 0;
    for(int i = x; i; i -= (i & -i)){
        for(int j = y; j; j -= (j & -j)){
            ans += tree[i][j];
        }
    }
    return ans;
}

int main()
{
    //srand((unsigned)time(NULL));
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < q; i++){
        int t, r1, c1, r2, c2;
        scanf("%d%d%d%d%d", &t, &r1, &c1, &r2, &c2);
        if(t == 1){
            ll val = Hash(r1, c1, r2, c2);
            add(r1, c1, n, m, val);
            add(r1, c2 + 1, n, m, -val);
            add(r2 + 1, c1, n, m, -val);
            add(r2 + 1, c2 + 1, n, m, val);
        }
        else if(t == 2){
            ll val = query(r1, c1 - 1) - query(r1, c1);
            add(r1, c1, n, m, val);
            add(r1, c2 + 1, n, m, -val);
            add(r2 + 1, c1, n, m, -val);
            add(r2 + 1, c2 + 1, n, m, val);
        }
        else if(t == 3){
            ll v1 = query(r1, c1);
            ll v2 = query(r2, c2);
            if(v1 == v2)printf("Yes\n");
            else printf("No\n");
        }
    }

	return 0;
}


