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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x">>>x:%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
string s[maxn];

bool cmp(string a, string b)
{
    string c = a+b;
    string d = b+a;
    ll cnt = 0, c1 = 0, d1 = 0;
    for(int i = c.size()-1; i >= 0; i--){
        if(c[i]=='h')cnt++;
        else c1 += cnt;
    }
    cnt = 0;
    for(int i = d.size()-1; i >= 0; i--){
        if(d[i]=='h')cnt++;
        else d1 += cnt;
    }
    return c1 > d1;
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    ll ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        //cout << s[i] << endl;
        for(int j = 0; j < (int)s[i].size(); j++){
            if(s[i][j]=='h')cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (int)s[i].size(); j++){
            if(s[i][j]=='s')ans += cnt;
            else cnt--;
        }
    }
    printf("%lld\n", ans);
	return 0;
}

