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
const int maxn = 1e2+10;
char s[maxn][maxn];
char ans[maxn][maxn];

char get(int x) {
    if(x < 26)return x+'a';
    else if(x < 52)return x-26+'A';
    else return x-52+'0';
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int tot = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            for(int j = 0; j < m; j++) {
                if(s[i][j] == 'R') tot++;
            }
        }
        int each = tot/k;
        int cur = 0, id = 0;
        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                for(int j = 0; j < m; j++) {
                    ans[i][j] = get(id);
                    if(s[i][j] == 'R')cur++;
                    if(cur > each || (cur == each && id >= tot%k)) {
                        cur = 0;
                        id = min(k-1, id+1);
                    }
                }
            }
            else {
                for(int j = m-1; j >= 0; j--) {
                    ans[i][j] = get(id);
                    if(s[i][j] == 'R')cur++;
                    if(cur > each || (cur == each && id >= tot%k)) {
                        cur = 0;
                        id = min(k-1, id+1);
                    }
                }
            }
            ans[i][m] = 0;
        }
        for(int i = 0; i < n; i++) {
            printf("%s\n", ans[i]);
        }
    }
    return 0;
}

