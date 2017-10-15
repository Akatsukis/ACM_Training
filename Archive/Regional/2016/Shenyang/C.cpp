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


const ll mod = 2147493647;
const int maxn = 7;
ll n, a, b;
typedef struct mat
{
    ll a[7][7];
    void init()
    {
        for(int i = 0; i < maxn; i++){
            for(int j = 0; j < maxn; j++){
                a[i][j] = 0;
            }
        }
    }
}mat;

mat mul(mat A, mat B)
{
    mat C;
    C.init();
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            ll now = 0;
            for(int k = 0; k < maxn; k++){
                now += (A.a[i][k] * B.a[k][j]) % mod;
                now %= mod;
            }
            C.a[i][j] += now;
            C.a[i][j] %= mod;
        }
    }
    return C;
}

mat pow_mod(mat A, ll n)
{
    mat res;
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            if(i == j)res.a[i][j] = 1;
            else res.a[i][j] = 0;
        }
    }
    while(n){
        if(n & 1)res = mul(res, A);
        A = mul(A, A);
        n >>= 1;
    }
    return res;
}



int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        mat q =
        {
        1, 2, 1, 4, 6, 4, 1,
        1, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 4, 6, 4, 1,
        0, 0, 0, 1, 3, 3, 1,
        0, 0, 0, 0, 1, 2, 1,
        0, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 0, 1
        };
        scanf("%I64d%I64d%I64d", &n, &a, &b);
        if(n == 1){
            printf("%I64d\n", a);
        }
        else if(n == 2){
            printf("%I64d\n", b);
        }
        else{
            mat ans = pow_mod(q, n - 2);
            ll res = 0;
            res += (ans.a[0][0] * b) % mod;
            res += (ans.a[0][1] * a) % mod;
            res += (ans.a[0][2] * 16) % mod;
            res += (ans.a[0][3] * 8) % mod;
            res += (ans.a[0][4] * 4) % mod;
            res += (ans.a[0][5] * 2) % mod;
            res += (ans.a[0][6] * 1) % mod;
            res %= mod;
            printf("%I64d\n", res);
        }
    }
	return 0;
}


