#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define fi first
#define se second
const int maxn = 1e4+10;
pair<pii, int> tb[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n; sc(n);
        for(int i = 1; i <= 3*n; i++){
            sc(tb[i].fi.fi);
            sc(tb[i].fi.se);
            tb[i].se = i;
        }
        sort(tb+1, tb+1+3*n);
        for(int i = 1; i <= 3*n; i++){
            printf("%d%c", tb[i].se, " \n"[i%3==0]);
        }
    }
}
