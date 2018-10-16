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
const int maxn = 1e4+10;
char s[maxn],  ans[maxn];
int nxt[maxn];
int n;

void get_next()
{
    n = strlen(s);
    int k = -1;
    nxt[0] = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[k+1] != s[i])k = nxt[k];
        if(s[k+1] == s[i])k++;
        nxt[i] = k;
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%s", s);
        get_next();
        bool flg = 0;
        for(int i = 1; i < n-1; i++){
            if(nxt[i] != -1 && nxt[i+1] == -1){
                flg = 1;
                int cnt = 0;
                for(int j = 0; j < i; j++)ans[cnt++] = s[j];
                for(int j = 0; j < n; j++)ans[cnt++] = s[j];
                ans[cnt] = 0;
                printf("Case #%d: %s\n", kase++, ans);
                break;
            }
        }
        if(!flg)printf("Case #%d: Impossible\n", kase++);
    }
    return 0;
}

