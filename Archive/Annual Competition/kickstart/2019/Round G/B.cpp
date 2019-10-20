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
const int maxn = 1e3+10;
long long a[maxn];
int bit[64][2];
int n;
long long m;

long long calc(int curBit, long long curTot, long long curM) {
    if(curBit == -1) {
        if(curTot > m)return -1;
        else return curM;
    }
    long long maxVal = curTot+(1LL<<(curBit+1))*n;
    if(maxVal <= curTot) {
        return curM|((1LL<<(curBit+1))-1);
    }
    long long v1 = -1, v2 = -1;
    if(curTot+bit[curBit][0]*(1LL<<curBit) <= m) {
        v1 = calc(curBit-1, curTot+bit[curBit][0]*(1LL<<curBit), curM|(1LL<<curBit));
        if(v1 != -1)return v1;
    }
    if(curTot+bit[curBit][1]*(1LL<<curBit) <= m) {
        v2 = calc(curBit-1, curTot+bit[curBit][1]*(1LL<<curBit), curM);
        if(v2 != -1)return v2;
    }
    return -1;
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        memset(bit, 0, sizeof(bit));
        scanf("%d%lld", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            for(int j = 0; j < 51; j++) {
                if(a[i]>>j&1) {
                    bit[j][1]++;
                }
                else {
                    bit[j][0]++;
                }
            }
        }
        long long ans = calc(50, 0, 0);
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

