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

void solve()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
        int cyc = i-nxt[i];
        if(nxt[i] != -1 && (i+1)%cyc == 0)printf("%d %d\n", i+1, (i+1)/cyc);
    }
}

int main()
{
    int kase = 1;
    while(scanf("%d", &n) != EOF && n){
        printf("Test case #%d\n", kase++);
        scanf("%s", s);
        solve();
        puts("");
    }
    return 0;
}

