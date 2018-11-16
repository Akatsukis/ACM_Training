#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
string s[maxn][maxn], t;
map<string, bool> mp;
int n;

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        cin >> n >> t;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 20; j++){
                cin >> s[i][j];
            }
        }
        int ans = -1;
        for(int y = 0; y <= n; y++){
            mp.clear();
            int u = n-y, v = y;
            for(int j = 0; j < 20; j++){
                for(int i = 0; i < 5; i++){
                    if(u && !mp.count(s[i][j])){
                        u--;
                        mp[s[i][j]] = 1;
                    }
                }
            }
            for(int j = 0; j < 20; j++){
                if(v && !mp.count(s[5][j])){
                    v--;
                    mp[s[5][j]] = 1;
                }
            }
            if(!mp.count(t)){
                ans = y;
                break;
            }
        }
        printf("Case #%d: ", kase++);
        if(ans == -1)printf("ADVANCED!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
