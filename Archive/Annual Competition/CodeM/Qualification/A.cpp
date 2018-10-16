#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20;
int a[maxn], b[maxn], c[maxn];
int tag[maxn];
double ans;
int n, m, sum;

void dfs(int now, int t)
{
    if(now >= b[t]){
        ans = min(ans, (double)now-c[t]);
        return;
    }
    for(int i = 0; i < n; i++){
        dfs(now+a[i], t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a[i], &tag[i]);
        if(tag[i])ans += 0.8*a[i];
        else ans += a[i];
        sum += a[i];
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", &b[i], &c[i]);
        if(sum >= b[i])ans = min(ans, (double)sum-c[i]);
    }
    for(int i = 0; i < m; i++){
        dfs(sum, i);
    }
    printf("%.2f\n", ans);
    return 0;
}

