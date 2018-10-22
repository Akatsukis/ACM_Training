#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 1e5+10;
int a[maxn], b[maxn];
int ans[maxn];
int n;
bool flg;

bool dfs(int t)
{
    if(t == n-1)return 1;
    for(int i = 0; i < 4; i++){
        if((ans[t]|i) == a[t] && (ans[t]&i) == b[t]){
            ans[t+1] = i;
            if(dfs(t+1))return 1;
        }
    }
    return 0;
}

int main()
{
    sc(n);
    for(int i = 0; i < n-1; i++)sc(a[i]);
    for(int i = 0; i < n-1; i++)sc(b[i]);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((i|j) == a[0] && (i&j) == b[0]){
                ans[0] = i, ans[1] = j;
                if(dfs(1)){
                    flg = 1;
                    break;
                }
            }
        }
        if(flg)break;
    }
    if(!flg)puts("NO");
    else{
        puts("YES");
        for(int i = 0; i < n; i++)printf("%d%c", ans[i], " \n"[i==n-1]);
    }
    return 0;
}

