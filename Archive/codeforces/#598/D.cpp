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
constexpr int maxn = 1e6+10;
char s[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        long long k;
        scanf("%d%lld", &n, &k);
        scanf("%s", s);
        vector<int> pos;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') pos.push_back(i);
        }
        vector<bool> zero(n);
        int cur = 0;
        for(int i = 0; i < (int)pos.size(); i++) {
            if(k >= pos[i]-cur) {
                k -= pos[i]-cur;
                zero[cur] = 1;
                cur++;
            }
            else {
                zero[pos[i]-k] = 1;
                k = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            if(zero[i])s[i] = '0';
            else s[i] = '1';
        }
        printf("%s\n", s);
    }
    return 0;
}

