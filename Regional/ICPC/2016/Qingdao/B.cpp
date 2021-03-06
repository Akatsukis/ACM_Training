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
int s[25];

int change[12][12] =
{
{5, 6, 23, 21, 16, 15, 18, 20, 1, 2, 4, 3},
{23, 21, 16, 15, 18, 20, 5, 6, 3, 1, 2, 4},
{7, 8, 24, 22, 14, 13, 17, 19, 9, 10, 12, 11},
{24, 22, 14, 13, 17, 19, 7, 8, 10, 12, 11, 9},
{1, 3, 5, 7, 9, 11, 13, 15, 18, 20, 19, 17},
{5, 7, 9, 11, 13, 15, 1, 3, 20, 19, 17, 18},
{2, 4, 6, 8, 10, 12, 14, 16, 23, 21, 22, 24},
{6, 8, 10, 12, 14, 16, 2, 4, 24, 23, 21, 22},
{9, 10, 24, 23, 4, 3, 20, 19, 5, 6, 8, 7},
{24, 23, 4, 3, 20, 19, 9, 10, 7, 5, 6, 8},
{1, 2, 21, 22, 12, 11, 17, 18, 13, 14, 16, 15},
{21, 22, 12, 11, 17, 18, 1, 2, 15, 13, 14, 16}
};

bool check(int a[])
{
    for(int i = 1, j = 0; i <= 24; i++, j++){
        if(j == 4)j = 0;
        if(a[i] != a[i - j])return false;
    }
    return true;
}

void solve()
{
    int tmp[25];
    memcpy(tmp, s, sizeof(s));
    if(check(tmp)){
        printf("YES\n");
        return;
    }
    for(int i = 0; i < 12; i++){
        memcpy(tmp, s , sizeof(s));
        for(int j = 0; j < 12; j++){
            tmp[change[i][j]] = s[change[i ^ 1][j]];
        }
        if(check(tmp)){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        for(int i = 1; i <= 24; i++){
            scanf("%d", &s[i]);
        }
        solve();
    }
	return 0;
}


