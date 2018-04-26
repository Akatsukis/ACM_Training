#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
const int maxn = 1e6+10;
char c[maxn];
int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%s", c);
        int n = strlen(c);
        int ans = 0;
        bool flg = 1;
        for(int i = 0; i < n; i++){
            if(c[i] == 'c')ans++;
            if(c[i] != 'c' && c[i] != 'f'){
                flg = 0;
                break;
            }
            if(c[i] == 'c'){
                if(i+1 < n && c[i+1] == 'c'){
                    flg = 0;
                    break;
                }
                if(i+2 < n && c[i+2] == 'c'){
                    flg = 0;
                    break;
                }
            }
        }
        if(c[n-1] == 'c' && c[0] == 'c')flg = 0;
        if(n > 1 && c[n-1] == 'c' && c[1] == 'c')flg = 0;
        if(n > 1 && c[n-2] == 'c' && c[0] == 'c')flg = 0;
        if(!flg)printf("Case #%d: %d\n", kase++, -1);
        else if(ans)printf("Case #%d: %d\n", kase++, ans);
        else printf("Case #%d: %d\n", kase++, (n+1)/2);
    }
    return 0;
}
