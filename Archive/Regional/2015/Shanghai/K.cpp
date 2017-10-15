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
char s[maxn];
ll num[maxn];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        memset(num, 0, sizeof(num));
        scanf("%s", s);
        int n = strlen(s);
        int id = 1;
        for(int i = 0; i < n; i++){
            int c = s[i];
            int cnt = 1;
            while(i + 1 < n && s[i + 1] == c)i++, cnt++;
            num[id++] = cnt;
        }
        ll ans = 0, cur = 0;
        for(int i = 1; i < id; i++){
            cur += (ll)num[i] * num[i];
        }
        if(id == 2){
            printf("Case #%d: %lld\n", kase++, cur);
            continue;
        }
        for(int i = 1; i < id; i++){
            if(num[i] == 1){
                if(i == 1){
                    ll pre = 1 + (ll)num[i+1]*num[i+1];
                    ll now = (ll)(num[i+1]+1)*(num[i+1]+1);
                    ll add = now - pre;
                    ans = max(ans, add);
                }
                else if(i == id - 1){
                    ll pre = 1 + (ll)num[i-1]*num[i-1];
                    ll now = (ll)(num[i-1]+1)*(num[i-1]+1);
                    ll add = now - pre;
                    ans = max(ans, add);
                }
                else{
                    ll pre = 1 + (ll)num[i-1]*num[i-1] + (ll)num[i+1]*num[i+1];
                    ll now = (ll)(num[i-1]+1+num[i+1])*(num[i-1]+1+num[i+1]);
                    ll add = now - pre;
                    ans = max(ans, add);
                }
            }
            else{
                if(i > 1){
                    ll pre = (ll)num[i-1]*num[i-1] + (ll)num[i]*num[i];
                    ll now = (ll)(num[i-1]+1)*(num[i-1]+1) + (ll)(num[i]-1)*(num[i]-1);
                    ll add = now - pre;
                    ans = max(ans, add);
                }
                if(i < id - 1){
                    ll pre = (ll)num[i+1]*num[i+1] + (ll)num[i]*num[i];
                    ll now = (ll)(num[i+1]+1)*(num[i+1]+1) + (ll)(num[i]-1)*(num[i]-1);
                    ll add = now - pre;
                    ans = max(ans, add);
                }
            }
        }
        printf("Case #%d: %lld\n", kase++, ans + cur);
    }
	return 0;
}


