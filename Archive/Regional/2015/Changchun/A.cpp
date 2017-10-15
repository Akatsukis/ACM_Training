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
int a[10];
int val[10] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int p;

int cal(int n, int m, int rev)
{
    //cout << rev << endl;
    bool flag1 = 0, flag2 = 0;
    int res = 0, now;
    if(n == 1){
        now = min(rev / 500, a[7]);
        if(now){
            flag1 = 1;
            rev -= 500;
            res++;
        }
    }
    if(m == 1){
        now = min(rev / 50, a[4]);
        if(now){
            flag2 = 1;
            rev -= 50;
            res++;
        }
    }
    for(int i = 9; i >= 0; i--){
        if(i == 7){
            if(flag1)now = min(rev / 500, a[7] - 1) / 2 * 2;
            else now = min(rev / 500, a[7]) / 2 * 2;
        }
        else if(i == 4){
            if(flag2)now = min(rev / 50, a[4] - 1) / 2 * 2;
            else now = min(rev / 50, a[4]) / 2 * 2;
        }
        else now = min(rev / val[i], a[i]);
        rev -= now * val[i];
        res += now;
        //cout << rev << endl;
    }
    if(rev)return INF;
    else return res;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(p);
        int sum = 0, cnt = 0;
        for(int i = 0; i < 10; i++){
            sc(a[i]);
            sum += a[i] * val[i];
            cnt += a[i];
        }
        if(sum < p){
            printf("-1\n");
            continue;
        }
        int rev = sum - p;
        int ans = INF;
        ans = min(ans, cal(0, 0, rev));
        ans = min(ans, cal(0, 1, rev));
        ans = min(ans, cal(1, 0, rev));
        ans = min(ans, cal(1, 1, rev));
        if(ans != INF)printf("%d\n", cnt - ans);
        else printf("-1\n");
    }
	return 0;
}


