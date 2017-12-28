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
set<int> st;
set<int> tmp;

void del(int x)
{
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

int main()
{
    scanf("%s", s+1);
    n = strlen(s+1);
    for(int i = 1; i < n; i++){
        if(s[i] != s[i+1]){
            st.insert(i);
            st.insert(i+1);
        }
    }
    for(int i = 1; i <= n; i++){
        pre[i] = i-1;
        nxt[i] = i+1;
    }
    int ans = 0;
    while(st.size()){
        ans++;
        tmp.clear();
        for(auto it = st.begin(); it != st.end(); it++){
            int u = *it;
            int l = pre[u], r = nxt[u];
            if(tmp.count(u))tmp.erase(u);
            if(tmp.count(l))tmp.erase(l);
            if(tmp.count(r))tmp.erase(r);
            del(u);
            if(l != 0 && l != n+1){
                if((pre[l]!=0&&s[l]!=s[pre[l]]) || (nxt[l]!=n+1&&s[l]!=s[nxt[l]])){
                    tmp.insert(l);
                }
            }
            if(r != 0 && r != n+1){
                if((pre[r]!=0&&s[r]!=s[pre[r]]) || (nxt[r]!=n+1&&s[r]!=s[nxt[r]])){
                    tmp.insert(r);
                }
            }
        }
        st = tmp;
    }
    printf("%d\n", ans);
    return 0;
}

