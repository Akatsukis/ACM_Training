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
const int maxm = 1e5 + 10;
int n, m;
pii p[maxn];
pii q[maxm];
multiset<int> st;
multiset<int>::iterator it;

bool cmp1(const pii &a, const pii &b)
{
    if(a.fi != b.fi)return a.fi > b.fi;
    return a.fi < b.fi;
}

bool cmp2(const pii &a, const pii &b)
{
    if(a.se != b.se)return a.se > b.se;
    return a.fi < b.se;
}


void work()
{
    st.clear();
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        sc(p[i].fi);sc(p[i].se);
    }
    for(int i = 0; i < m; i++){
        sc(q[i].fi);sc(q[i].se);
    }
    sort(p, p + n, cmp1);
    sort(q, q + m, cmp2);
    int pos = -1, ans = n;
    for(int i = 0; i < m; i++){
        while(pos != n - 1 && p[pos + 1].fi >= q[i].se){
            pos++;
            st.insert(p[pos].se);
        }
        //printf("st.size()=%d\n", st.size());
        if(!st.size()){
            printf("-1\n");
            return;
        }
        it = st.upper_bound(q[i].fi);
        if(it == st.end()){
            it = st.lower_bound(0);
            st.erase(it++);
            ans--;
        }
        else{
            st.erase(it++);
        }
        //printf("ans=%d\n", ans);
    }
    printf("%d\n", ans);

}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        printf("Case #%d: ", kase++);
        work();
    }
    return 0;
}


