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
const int INF = 1e9 + 10;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, k;
int a[100100];
int b[100100];
int c[100100];

int main()
{
    sc(n);sc(k);
    int maxx = -INF, minn = INF;
    for(int i = 0; i < n; i++){
        sc(a[i]);
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    if(k == 1){
        printf("%d\n", minn);
        return 0;
    }
    if(k >= 3){
        printf("%d\n", maxx);
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(i){
            b[i] = min(b[i - 1], a[i]);
            c[n - i - 1] = min(c[n - i], a[n - i - 1]);
        }
        else{
            b[i] = a[i];
            c[n - i - 1] = a[n - i - 1];
        }
        //cout << b[i] << c[n - i - 1] << endl;
    }
    int ans = minn;
    for(int i = 0; i < n - 1; i++){
        if(max(b[i], c[i + 1]) >= ans){
            ans = max(b[i], c[i + 1]);
        }
    }
    printf("%d\n", ans);
	return 0;
}


