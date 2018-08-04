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
const int maxn = 3e5+10;
int a[3][maxn];
ll sum[2][3][maxn];
ll tb[2][3][maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= n; j++)sc(a[i][j]);
    }
    ll pre1 = 0, pre2 = 0, cnt = 0;
    for(int i = 1; i <= 2; i++){
        if(i == 1){
            for(int j = 1; j <= n; j++){
                sum[0][i][j] = pre1+cnt*a[i][j];
                tb[0][i][j] = pre2+a[i][j];
                pre1 = sum[0][i][j], pre2 = tb[0][i][j];
                cnt++;
            }
        }   
        else{
            for(int j = n; j >= 1; j--){
                sum[0][i][j] = pre1+cnt*a[i][j];
                tb[0][i][j] = pre2+a[i][j];
                pre1 = sum[0][i][j], pre2 = tb[0][i][j];
                cnt++;
            }

        }
    }
    pre1 = pre2 = cnt = 0;
    for(int i = 2; i >= 1; i--){
        if(i == 2){
            for(int j = 1; j <= n; j++){
                sum[1][i][j] = pre1+cnt*a[i][j];
                tb[1][i][j] = pre2+a[i][j];
                pre1 = sum[1][i][j], pre2 = tb[1][i][j];
                cnt++;
            }
        }   
        else{
            for(int j = n; j >= 1; j--){
                sum[1][i][j] = pre1+cnt*a[i][j];
                tb[1][i][j] = pre2+a[i][j];
                pre1 = sum[1][i][j], pre2 = tb[1][i][j];
                cnt++;
            }

        }
    }
    cnt = 0;
    ll ans = sum[0][2][1];
    for(int i = 1; i <= n; i++){
        ll now1 = 0, now2 = 0;
        if(i%2 == 1){
            now1 = sum[0][2][i]-sum[0][1][i-1]+(ll)(i-1)*(tb[0][2][i]-tb[0][1][i-1]);
            now2 = (ll)(i*2-2)*a[1][i]+sum[1][1][i+1]-sum[1][2][i-1]+(ll)i*(tb[1][1][i+1]-tb[1][2][i-1]);
        }
        else{
            now1 = (ll)(i*2-2)*a[2][i]+sum[0][2][i+1]-sum[0][1][i-1]+(ll)i*(tb[0][2][i+1]-tb[0][1][i-1]);
            now2 = sum[1][1][i]-sum[1][2][i-1]+(ll)(i-1)*(tb[1][1][i]-tb[1][2][i-1]);
        }
        ans = max(ans, max(now1+cnt, now2+cnt));
        if(i%2 == 1){
            cnt += (ll)(i*2-2)*a[1][i];
            cnt += (ll)(i*2-1)*a[2][i];
        }
        else{
            cnt += (ll)(i*2-2)*a[2][i];
            cnt += (ll)(i*2-1)*a[1][i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}


