#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e5+10;
int tag[maxn][2];
int n, m;

long long qpow(long long a, int n)
{
    long long ret = 1;
    while(n){
        if(n&1)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 2; j++)tag[i][j] = 0;
        }
        for(int i = 0; i < m; i++){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            tag[l][x-2]++; tag[r+1][x-2]--;
        }
        int m2 = INF, m3 = INF, cnt2 = 0, cnt3 = 0;
        for(int i = 1; i <= n; i++){
            cnt2 += tag[i][0]; cnt3 += tag[i][1];
            m2 = min(m2, cnt2), m3 = min(m3, cnt3);
        }
        int ans = qpow(2, m2)*qpow(3, m3)%mod;
        printf("%d\n", ans);
    }
    return 0;
}
