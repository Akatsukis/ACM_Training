#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
map<string, int> mp;
char s[maxn];
int n;

void init()
{
    mp["char"]          = 1;
    mp["int"]           = 4;
    mp["long long"]     = 8;
    mp["__int128"]      = 16;
    mp["float"]         = 4;
    mp["double"]        = 8;
    mp["long double"]   = 16;
    mp["bool"]          = 1;
}

int main()
{
    init();
    int T, kase = 1;
    scanf("%d\n", &T);
    while(T--){
        scanf("%d\n", &n);
        int tot = 0;
        for(int i = 0; i < n; i++){
            fgets(s, maxn, stdin);
            int len = strlen(s), num = 0;
            string type;
            int j = 0;
            while(j < len && s[j] != ' ')type += s[j++];
            if(type == "long"){
                type += s[j++];
                while(j < len && isalpha(s[j]))type += s[j++];
            }
            else j++;
            while(j < len && !isdigit(s[j]))j++;
            while(j < len && isdigit(s[j]))num = num*10+s[j++]-'0';
            if(!num)num = 1;
            tot += mp[type]*num;
        }
        int ans = (tot+1023)/1024;
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}
