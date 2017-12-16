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
const int maxn = 1e5 + 10;
int a[maxn];
int tr[maxn];
int t[maxn];
int ni[maxn];
int pre[maxn];
int sub[maxn];
int n;

void add(int *tt,int i, int x)
{
    while(i <= n){
        tt[i] += x;
        i += i&(-i);
    }
}

int sum(int *tt, int i)
{
    int res = 0;
    while(i){
        res += tt[i];
        i -= i&(-i);
    }
    return res;
}

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        add(tr, a[i], 1);
        ni[i] = i - sum(tr, a[i]);
  //      pr(ni[i]);
        if(ni[i]==1)add(t,a[i],1);
    }
    int mx = a[1];
    int ans = sum(t,a[1]-1)-(ni[2]==1&&a[1]>a[2]), ansi = a[1];
    //pr(ans);
    for(int i = 2; i <= n; i++){
        if(ni[i-1]==1)add(t,a[i-1],-1);
        int tmp = 0;
        tmp = sum(t,a[i]-1)-(mx<a[i])-(i<n?(ni[i+1]==1&&a[i]>a[i+1]):0);
//        pr(tmp);
        if(tmp==ans)ansi=min(ansi,a[i]);
        if(tmp>ans){
            ans=tmp,ansi=a[i];
        }
    }
    printf("%d\n", ansi);
//    sc(n);
//    for(int i = 1; i <= n; i++){
//        sc(a[i]);
//        add(a[i], 1);
//        ni[i] = i - sum(a[i]);
//    }
//    for(int i = 1; i <= n; i++){
//        pre[i] = pre[i - 1];
//        if(ni[i-1] == 0 && i != 1)pre[i]++;
//    }
//    for(int i = n - 1; i >= 1; i--){
//        sub[i] = sub[i+1];
//        if(ni[i+1] <= 1)sub[i]++;
//    }
//    int cnt = 0, ans = n;
//    for(int i = 1; i <= n; i++){
//        if(pre[i] + sub[i] >= cnt){
//            cnt = pre[i] + sub[i];
//            ans = min(ans, a[i]);
//        }
//    }
//    for(int i = 1; i <= n; i++){
//        printf("pre[%d]:%d\n", i, pre[i]);
//        printf("sub[%d]:%d\n", i, sub[i]);
//        printf("ni[%d]:%d\n", i, ni[i]);
//    }
//    pr(cnt);
//    printf("%d\n", ans);
    return 0;
}

