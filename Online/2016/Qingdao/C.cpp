#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
const int maxlen = 30;
struct Trie
{
    int nxt[maxlen];
    int fail, last;
    void init()
    {
        memset(nxt, -1, sizeof(nxt));
        fail = last = 0;
    }
}trie[maxn];
char s[maxn];
int idx;

void Insert()
{
    int rt = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        int c = s[i]-'a';
        int &u = trie[rt].nxt[c];
        if(u == -1){
            u = ++idx;
            trie[idx].init();
        }
        rt = trie[rt].nxt[c];
    }
    trie[rt].last = n;
}

void get_fail()
{
    int rt = 0;
    queue<int> q;
    for(int i = 0; i < maxlen; i++){
        int &u = trie[rt].nxt[i];
        if(u == -1)u = rt;
        else{
            trie[u].fail = rt;
            q.push(u);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < maxlen; i++){
            int &v = trie[u].nxt[i];
            int w = trie[u].fail;
            if(v == -1)v = trie[w].nxt[i];
            else{
                trie[v].fail = trie[w].nxt[i];
                q.push(v);
            }
        }
    }
}

void Query()
{
    int n = strlen(s);
    int rt = 0;
    for(int i = 0; i < n; i++){
        if(!isalpha(s[i])){
            rt = 0;
            continue;
        }
        int c = tolower(s[i])-'a';
        //printf("%c", c);
        rt = trie[rt].nxt[c];
        int tmp = rt;
        while(tmp){
            if(trie[tmp].last){
                //printf("tmp=%d\n", tmp);
                for(int j = 0; j < trie[tmp].last; j++){
                    s[i-j] = '*';
                }
            }
            tmp = trie[tmp].fail;
        }
    }
}

int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        idx = 0;
        trie[0].init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            Insert();
        }
        get_fail();
        scanf(" ");
        fgets(s, maxn-1, stdin);
        Query();
        printf("%s", s);
    }
    return 0;
}
