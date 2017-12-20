#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 150+10;
int a[maxn], b[maxn], tmp[maxn];

void solve(int t)
{
    if(t == 0)return;
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1; i <= 150; i++){
        tmp[i] += a[i-1];
    }
    for(int i = 0; i <= 150; i++){
        tmp[i] += b[i];
    }
    bool flag = 1;
    for(int i = 0; i <= 150; i++){
        if(tmp[i] > 1 || tmp[i] < -1){
            flag = 0;
            break;
        }
    }
    int mxa = 0, mxb = 0;
    for(int i = 0; i <= 150; i++){
        if(tmp[i])mxa = i;
        if(b[i])mxb = i;
    }
    if(flag && mxa >= mxb){
        memcpy(b, a, sizeof(a));
        memcpy(a, tmp, sizeof(a));
        solve(t-1);
        return;
    }
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1; i <= 150; i++){
        tmp[i] += -a[i-1];
    }
    for(int i = 0; i <= 150; i++){
        tmp[i] += b[i];
    }
    flag = 1;
    for(int i = 0; i <= 150; i++){
        if(tmp[i] > 1 || tmp[i] < -1){
            flag = 0;
            break;
        }
    }
    flag = 1;
    mxa = 0, mxb = 0;
    for(int i = 0; i <= 150; i++){
        if(tmp[i])mxa = i;
        if(b[i])mxb = i;
    }
    if(flag && mxa >= mxb){
        memcpy(b, a, sizeof(a));
        memcpy(a, tmp, sizeof(a));
        solve(t-1);
        return;
    }
}

int main()
{
    int n;
    sc(n);
    a[0] = 1;
    solve(n);
    int mxa = 0, mxb = 0;
    for(int i = 0; i <= 150; i++){
        if(a[i])mxa = i;
        if(b[i])mxb = i;
    }
    if(a[mxa] == -1)for(int i = 0; i <= 150; i++)a[i] = -a[i];
    if(b[mxb] == -1)for(int i = 0; i <= 150; i++)b[i] = -b[i];
    printf("%d\n", mxa);
    for(int i = 0; i <= mxa; i++){
        printf("%d%c", a[i], i == mxa ? '\n' : ' ');
    }
    printf("%d\n", mxb);
    for(int i = 0; i <= mxb; i++){
        printf("%d%c", b[i], i == mxb ? '\n' : ' ');
    }
    return 0;
}

