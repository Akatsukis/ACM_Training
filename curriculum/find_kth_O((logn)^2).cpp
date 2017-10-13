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

int solve(int n)
{
    int l[2], r[2];
    l[0] = l[1] = 0, r[0] = r[1] = n - 1;
    int k = n;
    while(l[0] <= r[0] && l[1] <= r[1] && k != 1){
        printf("%d %d %d %d %d\n", l[0], r[0], l[1], r[1], k);
        int m[2];
        m[0] = (l[0] + r[0]) / 2, m[1] = (l[1] + r[1]) / 2;
        cout << a[m[0]] << b[m[1]] << endl;
        if(a[m[0]] >= b[m[1]]){
            int cur = (m[0]-l[0]+1) + (m[1]-l[1]+1);
            if(cur >= k){
                r[0] = m[0];
            }
            else{
                k -= (m[1]-l[1]+1);
                l[1] = m[1] + 1;
            }
        }
        else{
            int cur = (m[0]-l[0]+1) + (m[1]-l[1]+1);
            if(cur >= k){
                r[1] = m[1];
            }
            else{
                k -= (m[0]-l[0]+1);
                l[0] = m[0] + 1;
            }
        }
    }
    if(l[0] > r[0])return b[l[1]];
    if(l[1] > r[1])return a[l[1]];
    return a[l[1]] < b[l[1]] ? a[l[1]] : b[l[1]];
}

int main()
{
    frein;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    int ans = solve(n);
    printf("%d\n", ans);
	return 0;
}


