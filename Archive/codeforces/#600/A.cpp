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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            a[i] -= b[i];
        }
        bool flg = 1;
        for(int i = 0; i < n; i++) {
            if(a[i] != 0) {
                if(a[i] > 0) {
                    flg = 0;
                    break;
                }
                int j = 1;
                while(i+j < n && a[i+j] == a[i]) j++;
                while(i+j < n && a[i+j] == 0) j++;
                if(i+j != n) flg = 0;
                break;
            }
        }
        if(flg) puts("YES");
        else puts("NO");
    }
    return 0;
}

