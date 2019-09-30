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

unsigned long long k1, k2;
unsigned long long rng() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        if(p == 1) {
            for(int i = 0; i < n; i++) scanf("%d", &a[i]);
            for(int i = 0; i < m; i++) scanf("%d", &b[i]);
        }
        else {
            int mod;
            scanf("%llu%llu%d", &k1, &k2, &mod);
            for(int i = 0; i < n; i++) a[i] = rng()%mod;
            scanf("%llu%llu%d", &k1, &k2, &mod);
            for(int i = 0; i < m; i++) b[i] = rng()%mod;
        }
        map<int, int> mp1, mp2;
        for(int i = 0; i < n; i++) {
            mp1[a[i]]++;
        }
        for(int i = 0; i < m; i++) {
            mp2[b[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto p: mp2) {
            int v = p.first;
            if(mp1.count(v)) {
                pq.push(make_pair(mp1[v]+mp2[v], v));
            }
        }
        int turn = 0;
        while(pq.size()) {
            int v = pq.top().second; pq.pop();
            if(turn == 0) {
                if(n <= 0)break;
                n--; m -= mp2[v];
            }
            else {
                if(m <= 0)break;
                m--; n -= mp1[v];
            }
            turn ^= 1;
        }
        bool flg = 0;
        if(turn == 0) {
            if(n == 0)flg = 1;
            else {
                if(n > m)flg = 0;
                else flg = 1;
            }
        }
        else {
            if(m == 0)flg = 0;
            else {
                if(m > n)flg = 1;
                else flg = 0;
            }
        }
        if(flg == 0)puts("Cuber QQ");
        else puts("Quber CC");
    }
    return 0;
}
