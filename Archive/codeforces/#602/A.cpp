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
constexpr int maxn = 2e3+10;
char s[maxn], t[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        int m = 0;
        for(int i = 0; i < n/2-k+1; i++) {
            t[m++] = '(';
        }
        for(int i = 0; i < n/2-k+1; i++) {
            t[m++] = ')';
        }
        while(m < n) {
            t[m++] = '(';
            t[m++] = ')';
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                for(int j = i+1; j < n; j++) {
                    if(s[j] == t[i]) {
                        ans.push_back(make_pair(i, j));
                        reverse(s+i, s+j+1);
                        break;
                    }
                }
            }
        }
        printf("%d\n", (int)ans.size());
        for(auto p: ans) {
            printf("%d %d\n", p.first+1, p.second+1);
        }
    }
    return 0;
}

