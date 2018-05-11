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
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
char s[maxn], t[maxn];
int ma[maxn], sum[maxn], w[26];
int n;

void manacher()
{
    t[0] = '$', t[1] = '#';
    for(int i = 0; i < n; i++){
        t[i*2+2] = s[i], t[i*2+3] = '#';
    }
    int mx = -1, ctr = -1;
    for(int i = 1; i < 2*n+2; i++){
        if(mx > i)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(t[i-ma[i]] == t[i+ma[i]])ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        for(int i = 0; i < 26; i++)sc(w[i]);
        scanf("%s", s);
        n = strlen(s);
        sum[0] = w[s[0]-'a'];
        for(int i = 1; i < n; i++)sum[i] = sum[i-1]+w[s[i]-'a'];
        manacher();
        int ans = -INF;
        for(int i = 0; i < n-1; i++){
            int now = 0;
            if(ma[i+2]-1 >= i+1)now += sum[i];
            if(ma[i+2+n]-1 >= n-i-1)now += sum[n-1]-sum[i];
            ans = max(ans, now);
        }
        printf("%d\n", ans);
    }
    return 0;
}

