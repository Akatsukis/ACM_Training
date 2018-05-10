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
const int maxn = 4e5+10;
char s[maxn], t[maxn];
int ma[maxn];
int mp[26];

void solve()
{
    t[0] = '$', t[1] = '#';
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        t[i*2+2] = s[i], t[i*2+3] = '#';
    }
    int mx = -1, ctr = -1, ret = 1, ans = -1;
    for(int i = 1; i < 2*n+2; i++){
        if(mx > i)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(t[i-ma[i]] == t[i+ma[i]])ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
        if(ma[i]-1 > ret){
            ret = ma[i]-1;
            ans = i;
        }
    }
    if(ret < 2)printf("No solution!\n");
    else{
        string res;
        for(int i = ans-ret; i <= ans+ret; i++){
            if(t[i] == '#')continue;
            else res.pb(char(mp[t[i]-'a']+'a'));
        }
        cout << (ans-1)/2-ret/2 << " " << (ans-1)/2+(ret-1)/2 << endl;
        cout << res << endl;
    }
}

int main()
{
    char ch[2];
    while(scanf("%s %s", ch, s) != EOF){
        for(int i = 0; i < 26; i++)mp[(ch[0]-'a'+i)%26] = i;
        solve();
    }
    return 0;
}

