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
const int maxn = 1e5+10;
char s[maxn];
int nxt[maxn];

int solve()
{
    nxt[0] = -1;
    int n = strlen(s), k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
    int cyc = n-nxt[n-1]-1;
    if(n%cyc==0 && nxt[n-1] != -1)return 0;
    else return cyc-n%cyc;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%s", s);
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}

