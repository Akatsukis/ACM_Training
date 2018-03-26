#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
int n, m, p;
const int maxn = 1e6+10;
int a[maxn];
int b[maxn];
int nxt[maxn];

void get_next()
{
    int k = 0;
    for(int i = 1; i < m; i++){
        while(k && b[i] != b[k])k = nxt[k-1];
        if(b[i] == b[k])k++;
        nxt[i] = k;
    }
//    for(int i = 0; i < m; i++){
//        printf("nxt[%d]:%d\n", i, nxt[i]);
//    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(nxt, 0, sizeof(nxt));
        scanf("%d%d%d", &n, &m, &p);
        for(int i = 0; i < n; i++)sc(a[i]);
        for(int i = 0; i < m; i++)sc(b[i]);
        get_next();
        int ans = 0;
        for(int i = 0; i < p; i++){
            int k = 0;
            for(int j = i; j < n; j += p){
                while(k && a[j] != b[k])k = nxt[k-1];
                if(a[j] == b[k])k++;
                if(k == m)ans++;
                //printf("i=%d, k=%d\n", i, k);
            }
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
}
