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
int a[maxn], nxt[maxn];
int mp[26], rev[26];
int n;

void get_next()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && a[i] != a[k+1])k = nxt[k];
        if(a[i] == a[k+1])k++;
        nxt[i] = k;
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%s", s);
        for(int i = 0; i < 26; i++)mp[i] = s[i]-'a', rev[s[i]-'a'] = i;
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; i++)a[i] = s[i]-'a';
        get_next();
        int k = -1;
        for(int i = 1; i < n; i++){
            while(k >= 0 && mp[a[i]] != a[k+1])k = nxt[k];
            if(mp[a[i]] == a[k+1])k++;
        }
        int cyc = n-k-1;
        int times = (n+cyc-1)/cyc;
        times = (times+1)/2*2;
        cyc *= times/2;
        cyc = times%2&&times!=1?cyc*2:cyc;
        for(int i = cyc; i < 2*cyc; i++)s[i] = rev[a[i-cyc]]+'a';
        s[2*cyc] = 0;
        printf("%s\n", s);
    }
    return 0;
}

