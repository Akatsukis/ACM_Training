#include <bits/stdc++.h>
using namespace std;
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d",&x)
const int maxn = 1e6;
typedef long long ll;
double sum[maxn+10];
char s[maxn+10];

void init()
{
    for(ll i = 1; i < maxn; i++){
        sum[i] = sum[i-1]+1.0/sqr(i);
    }
}

int trs(char s[])
{
    int ret = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        ret = ret*10+s[i]-'0';
    }
    return ret;
}

int main()
{
    init();

    while(scanf("%s", s) != EOF){
        int n = strlen(s);
        if(n > 7){
            printf("%.5f\n", sum[maxn-1]);
            continue;
        }
        int ans = trs(s);
        if(ans >= maxn)printf("%.5f\n", sum[maxn-1]);
        else printf("%.5f\n", sum[ans]);
    }
    return 0;
}
