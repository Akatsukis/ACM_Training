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
const ll mod = 10007;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
char s[maxn];
int nxt[maxn], sz[maxn];
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
        sc(n);
        scanf("%s", s);
        get_next();
        int ans = 0;
        for(int i = 0; i < n; i++)sz[i] = 1;
        for(int i = n-1; i >= 0; i--){
            if(nxt[i] >= 0)sz[nxt[i]] += sz[i];
            ans = (ans+sz[i])%mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}

