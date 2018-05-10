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
const int maxn = 5e4+10;
char s[maxn], t[maxn];
int nxt[maxn];
int n, m;

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
    while(scanf("%s%s", s, t) != EOF){
        n = strlen(s), m = strlen(t);
        get_next();
        int k = -1;
        for(int i = 0; i < m; i++){
            while(k >= 0 && t[i] != s[k+1])k = nxt[k];
            if(t[i] == s[k+1])k++;
        }
        int ans = k+1;
        if(!ans)printf("0\n");
        else{
            s[ans] = 0;
            printf("%s %d\n", s, ans);
        }
    }
    return 0;
}

