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
const int maxn = 1e7+10;
int a[maxn], dq[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n, m, k, P, Q, R, MOD;
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &P, &Q, &R, &MOD);
        for(int i = 1; i <= k; i++)sc(a[i]);
        for(int i = k+1; i <= n; i++)a[i] = (1LL*P*a[i-1]+1LL*Q*i+R)%MOD;
        int front = 0, rear = 0;
        ll A = 0, B = 0;
        for(int l = n, r = n; l >= 1; r--){
            while(front != rear && dq[front] > r)dq[front++];
            while(l >= r-m+1){
                while(front != rear && a[l] >= a[dq[rear-1]])rear--;
                dq[rear++] = l;
                l--;
            }
            A += a[dq[front]]^(l+1);
            B += (rear-front)^(l+1);
        }
        printf("%lld %lld\n", A, B);
    }
    return 0;
}


