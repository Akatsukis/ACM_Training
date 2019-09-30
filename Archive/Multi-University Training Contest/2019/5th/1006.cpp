#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char t[maxn];
int nxt[maxn];
void get_next()
{
    int k = 0, n = strlen(t);
    while(k+1 < n && t[k]==t[k+1])k++;
    nxt[1] = k;
    int pos = 1;
    for(int i = 2; i < n; i++){
        if(i+nxt[i-pos] < pos+nxt[pos])nxt[i] = nxt[i-pos];
        else{
            k = max(0, pos+nxt[pos]-i);
            while(i+k < n && t[k] == t[i+k])k++;
            nxt[i] = k;
            pos = i;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", t);
        int n = strlen(t);
        get_next();
        long long ans = 0;
        for(int i = 1; i < n; i++) {
            ans += min(nxt[i]+1, n-i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
