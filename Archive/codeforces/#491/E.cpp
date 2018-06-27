#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define pb push_back
const int maxn = 20;
char s[maxn];
int a[maxn];
ll fac[maxn];
ll ans;

void dfs(int x, vector<int> &vec)
{
    if(x == 10){
        ll sum = 0;
        for(int i = 0; i < 10; i++){
            sum += vec[i];
        }
        ll ret = fac[sum];
        for(int i = 0; i < 10; i++){
            ret /= fac[vec[i]];
        }
        ans += ret;
        if(vec[0]){
            vec[0]--;
            sum = 0;
            for(int i = 0; i < 10; i++){
                sum += vec[i];
            }
            ret = fac[sum];
            for(int i = 0; i < 10; i++){
                ret /= fac[vec[i]];
            }
            ans -= ret;
            vec[0]++;
        }
        return;
    }
    if(!a[x]){
        vec.pb(0);
        dfs(x+1, vec);
        vec.pop_back();
    }
    else{
        for(int i = 1; i <= a[x]; i++){
            vec.pb(i);
            dfs(x+1, vec);
            vec.pop_back();
        }
    }
}

int main()
{
    fac[0] = 1;
    for(int i = 1; i < 20; i++)fac[i] = fac[i-1]*i;
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        a[s[i]-'0']++;
    }
    VI vec;
    dfs(0, vec);
    printf("%lld\n", ans);
    return 0;
}
