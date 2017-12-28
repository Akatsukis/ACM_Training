#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
char s[maxn];
int pre[maxn];
int nxt[maxn];
int n;
set<int> st[2];
int p, q;

void del(int x)
{
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

void Insert(int x)
{
    if(x == 0 || x == n+1)return;
    if((pre[x]!=0&&s[x]!=s[pre[x]])||(nxt[x]!=n+1&&s[x]!=s[nxt[x]]))st[q].insert(x);
}

int main()
{
    scanf("%s", s+1);
    n = strlen(s+1);
    for(int i = 1; i < n; i++){
        if(s[i] != s[i+1]){
            st[0].insert(i);
            st[0].insert(i+1);
        }
    }
    for(int i = 1; i <= n; i++){
        pre[i] = i-1;
        nxt[i] = i+1;
    }
    int ans = 0;
    p = 0, q = 1;
    while(st[p].size()){
        ans++;
        st[q].clear();
        for(auto it = st[p].begin(); it != st[p].end(); it++){
            int u = *it;
            int l = pre[u], r = nxt[u];
            if(st[q].count(u))st[q].erase(u);
            if(st[q].count(l))st[q].erase(l);
            if(st[q].count(r))st[q].erase(r);
            del(u);
            Insert(l);
            Insert(r);
        }
        swap(p, q);
    }
    printf("%d\n", ans);
    return 0;
}

