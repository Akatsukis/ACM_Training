#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e6+10;
char s[maxn], t[maxn];
int from[maxn], to[maxn];
int nxt[maxn], ext[maxn];
bool pal[maxn][2];
struct Node
{
    int nxt[maxn][26];
    ll cnt[maxn], num[maxn];
    int idx;
    void init()
    {
        memset(nxt, 0, sizeof(nxt));
        memset(cnt, 0, sizeof(cnt));
        memset(num, 0, sizeof(num));
        idx = 0;
    }
    void insert(char *ss, int l, int r)
    {
        int rt = 0;
        for(int i = l; i < r; i++){
            int ch = ss[i]-'a';
            cnt[rt] += pal[i][0];
            if(!nxt[rt][ch])nxt[rt][ch] = ++idx;
            rt = nxt[rt][ch];
        }
        num[rt]++;
    }
    ll get_ans(char *tt, int l, int r)
    {
        ll ret = 0;
        int rt = 0;
        for(int i = l; i < r; i++){
            int ch = tt[i]-'a';
            if(!nxt[rt][ch]){
                rt = -1;
                break;
            }
            else rt = nxt[rt][ch];
            if(i == r-1 || pal[i+1][1])ret += num[rt];
        }
        if(rt != -1)ret += cnt[rt];
        return ret;
    }
}trie;

void init()
{
    memset(nxt, 0, sizeof(nxt));
    memset(ext, 0, sizeof(ext));
    memset(pal, 0, sizeof(pal));
    trie.init();
}

void get_next(char *ss, int l, int r)
{
    int k = 0;
    while(l+k+1 < r && ss[l+k]==ss[l+k+1])k++;
    nxt[l+1] = k;
    int pos = l+1;
    for(int i = l+2; i < r; i++){
        if(i+nxt[l+i-pos] < pos+nxt[pos])nxt[i] = nxt[l+i-pos];
        else{
            k = max(0, pos+nxt[pos]-i);
            while(i+k < r && ss[l+k] == ss[i+k])k++;
            nxt[i] = k;
            pos = i;
        }
    }
    //for(int i = l; i < r; i++)printf("nxt[%d]=%d\n", i, nxt[i]);
}

void exKMP(char *ss, char *tt, int l, int r, bool t)
{
    get_next(tt, l, r);
    int k = 0;
    while(l+k < r && ss[l+k] == tt[l+k])k++;
    ext[l] = k;
    int pos = l;
    for(int i = l+1; i < r; i++){
        if(i+nxt[l+i-pos] < pos+ext[pos])ext[i] = nxt[l+i-pos];
        else{
            k = max(0, pos+ext[pos]-i);
            while(i+k < r && ss[i+k] == tt[l+k])k++;
            ext[i] = k;
            pos = i;
        }
    }
    for(int i = l; i < r; i++){
        if(ext[i] == r-i)pal[i][t] = 1;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        init();
        int tot = 0;
        for(int i = 0; i < n; i++){
            int len;
            scanf("%d%s", &len, s+tot);
            for(int j = 0; j < len; j++)t[tot+j] = s[tot+len-1-j];
            from[i] = tot, to[i] = tot+len;
            tot += len;
            exKMP(s, t, from[i], to[i], 0);
            exKMP(t, s, from[i], to[i], 1);
            trie.insert(s, from[i], to[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += trie.get_ans(t, from[i], to[i]);
            //printf("ans=%lld\n", ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

