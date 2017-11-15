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
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e5 + 10;
const int maxk = 100;
int a[maxn];
int pre[maxn];
int nxt[maxn];
int pos[maxn];
int s[maxk];
int t[maxk];
int n, k;

void del(int x)
{
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
}

ll cal(int o)
{
    int x = pos[o];
    ll res = 0;
    int cntl = 0, cntr = 0;
    s[0] = t[0] = x;
    for(int i = 1, j = pre[x]; i <= k; i++, j = pre[j]){
        s[i] = j;
        cntl++;
        if(j == 0)break;
    }
    for(int i = 1, j = nxt[x]; i <= k; i++, j = nxt[j]){
        t[i] = j;
        cntr++;
        if(j == n + 1)break;
    }
//    for(int i = 0; i <= cntl; i++){
//        printf("s[%d]:%d\n", i, s[i]);
//    }
//    for(int i = 0; i <= cntr; i++){
//        printf("t[%d]:%d\n", i, t[i]);
//    }
    for(int i = 0; i < cntl; i++){
        int j = k-i-1;
        if(j < cntr){
            res += 1LL*o*(s[i]-s[i+1])*(t[j+1]-t[j]);
            //printf("%lld\n", res);
        }
    }
    return res;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);sc(k);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
            pos[a[i]] = i;
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }
        pre[0] = 0, nxt[n];
        ll ans = 0;
        for(int i = 1;  i <= n; i++){
            ans += cal(i);
            del(pos[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

