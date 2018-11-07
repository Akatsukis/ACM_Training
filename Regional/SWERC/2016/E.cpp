#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
const int maxl = 30;
const int sigma = 26;
const int mod = 1e6+3;
int dp[maxl][maxn][2][2][2];
char s[maxl];
int L, R, n;

struct Node
{
    int nxt[maxn][sigma], fail[maxn], last[maxn], idx;
    int newNode()
    {
        int x = ++idx;
        memset(nxt[x], -1, sizeof(nxt[x]));
        fail[x] = last[x] = 0;
        return x;
    }
    void init()
    {
        idx = 0;
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = last[0] = 0;
    }
    void insert()
    {
        int rt = 0, len = strlen(s);
        for(int i = 0; i < len; i++){
            int u = s[i]-'a';
            if(nxt[rt][u] == -1)nxt[rt][u] = newNode();
            rt = nxt[rt][u];
        }
        last[rt]++;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 0; i < sigma; i++){
            int &u = nxt[rt][i];
            if(u == -1)u = rt;
            else{
                fail[u] = rt;
                q.push(u);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < sigma; i++){
                int &v = nxt[u][i];
                int w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    q.push(v);
                }
            }
        }
        for(int i = 1; i <= idx; i++){
            int tmp = i;
            while(tmp){
                if(last[tmp]){
                    last[i] = 1;
                    break;
                }
                tmp = fail[tmp];
            }
        }
    }
    int solve()
    {
        dp[0][0][0][0][0] = 1;
        for(int i = 0; i < R; i++){
            for(int j = 0; j <= idx; j++){
                for(int t = 0; t < 62; t++){
                    for(int k = 0; k < 2; k++){
                        for(int h = 0; h < 2; h++){
                            for(int l = 0; l < 2; l++){
                                int ns;
                                if(t >= 0 && t < 26)ns = nxt[j][t];
                                else if(t >= 26 && t < 52)ns = nxt[j][t-26];
                                else if(t == 52+0)ns = nxt[j]['o'-'a'];
                                else if(t == 52+1)ns = nxt[j]['i'-'a'];
                                else if(t == 52+3)ns = nxt[j]['e'-'a'];
                                else if(t == 52+5)ns = nxt[j]['s'-'a'];
                                else if(t == 52+7)ns = nxt[j]['t'-'a'];
                                else ns = 0;
                                if(last[ns])continue;
                                int nk = k|(t>=0&&t<26), nh = h|(t>=26&&t<52), nl = l|(t>=52&&t<62);
                                //printf("i=%d, ns=%d, nk=%d, nh=%d, nl=%d\n", i, ns, nk, nh, nl);
                                dp[i+1][ns][nk][nh][nl] = (dp[i+1][ns][nk][nh][nl]+dp[i][j][k][h][l])%mod;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = L; i <= R; i++){
            for(int j = 0; j <= idx; j++){
                ans = (ans+dp[i][j][1][1][1])%mod;
            }
        }
        return ans;
    }
}ACAM;

int main()
{
    ACAM.init();
    scanf("%d%d%d", &L, &R, &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        ACAM.insert();
    }
    ACAM.get_fail();
    int ans = ACAM.solve();
    printf("%d\n", ans);
    return 0;
}
