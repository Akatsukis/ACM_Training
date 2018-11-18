#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2+10;
string s[maxn];
bool vis[maxn];
ll pw[maxn];

void init()
{
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)pw[i] = pw[i-1]*2;
}

bool ok(string a, string b)
{
    if(a.size() < b.size())return 0;
    for(int i = 0; i < (int)b.size(); i++){
        if(a[i] != b[i])return 0;
    }
    return 1;
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    init();
    while(T--){
        int n, p;
        scanf("%d%d", &n, &p);
        for(int i = 0; i < p; i++)cin >> s[i], vis[i] = 0;
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
                if(i != j){
                    if(ok(s[i], s[j]))vis[i] = 1;
                }
            }
        }
        ll ans = pw[n];
        for(int i = 0; i < p; i++){
            if(!vis[i])ans -= pw[n-s[i].size()];
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}
