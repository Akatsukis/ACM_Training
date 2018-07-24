#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int maxn = 1e5+10;
const int maxs = 5e6+10;
char s[maxs];
int beg[maxn];
struct atom
{
    int x, y;
    bool operator < (const atom &rhs)const
    {
        int u = min(y, rhs.x), v = min(x, rhs.y);
        return u==v?x<rhs.x:u>v;
    }
}tb[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n; sc(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            tb[i].x = tb[i].y = 0; 
            scanf("%s", s+beg[i]);
            beg[i+1] = beg[i]+strlen(s+beg[i]);
            int cnt = 0;
            for(int j = beg[i]; j < beg[i+1]; j++){
                if(s[j] == '(')cnt++;
                else{
                    if(cnt)cnt--, ans++;
                    else tb[i].x++;
                }
            }
            tb[i].y = cnt;
        }
        sort(tb, tb+n);
        for(int i = 0, y = 0; i < n; i++){
            int k = min(y, tb[i].x);
            y += tb[i].y-k;
            ans += k;
        }
        printf("%d\n", ans*2);
    }
}
