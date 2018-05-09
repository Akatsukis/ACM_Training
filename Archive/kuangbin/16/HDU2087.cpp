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
const int maxn = 1e3+10;
char s[maxn], t[maxn];
int nxt[maxn];
int n, m;

void get_next()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < m; i++){
        while(k >= 0 && t[i] != t[k+1])k = nxt[k];
        if(t[i] == t[k+1])k++;
        nxt[i] = k;
    }
}

int main()
{
    while(scanf("%s", s) != EOF){
        if(s[0] == '#')break;
        scanf("%s", t);
        n = strlen(s), m = strlen(t);
        get_next();
        int ans = 0, k = -1;
        for(int i = 0; i < n; i++){
            while(k >= 0 && s[i] != t[k+1])k = nxt[k];
            if(s[i] == t[k+1])k++;
            if(k == m-1){
                ans++;
                k = -1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

