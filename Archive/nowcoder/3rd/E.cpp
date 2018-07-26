#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char s[maxn];
int nxt[maxn];
int n;

int get_next()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
    int cc = n-1-nxt[n-1];
    cc = n%cc?1:n/cc;
    return cc;
}

int main()
{
    scanf("%s", s);
    n = strlen(s);
    int cc = get_next();
    printf("%d\n", n/cc);
    for(int i = 0; i < n/cc; i++){
        printf("%d ", cc);
        for(int j = i; j < n; j += n/cc)printf("%d%c", j, " \n"[j+n/cc>=n]);
    }
}
