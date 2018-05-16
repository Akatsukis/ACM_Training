#include <bits/stdc++.h>
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
const int maxn = 1e6+10;
char s[maxn];
int nxt[maxn];
int n;

void get_next()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%s", s);
        n = strlen(s);
        get_next();
        vector<int> ans;
        int k = nxt[n-1];
        while(k != -1){
            ans.pb(k);
            k = nxt[k];
        }
        int ret = 0;
        for(auto u : ans){
            for(int j = 2*(u+1)-1; j < n-(u+1); j++){
                while(nxt[j] >= u){
                    if(nxt[j] == u){
                        ret = u+1;
                        break;
                    }
                    if(nxt[nxt[j]] >= u)nxt[j] = nxt[nxt[j]];
                    else break;
                }
                if(ret)break;
            }
            if(ret)break;
        }
        printf("%d\n", ret);
    }
    return 0;
}

