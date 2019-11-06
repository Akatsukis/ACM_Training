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

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        vector<string> str(n);
        int zero = 0, one = 0;
        bool flg = 1;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
            for(auto c: str[i]) {
                if(c == '0')zero++;
                else one++;
            }
            if(str[i].size()%2 == 1)flg = 0;
        }
        if(zero%2 == 0 && one%2 == 0)flg = 0;
        int ans = n;
        if(flg)ans--;
        printf("%d\n", ans);
    }
    return 0;
}

