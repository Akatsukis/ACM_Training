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

ll cal(string t)
{
    ll res = 0, cnt = 0;
    for(auto &c:t){
        if(c == 's')cnt++;
        else res += cnt;
    }
    return res;
}

bool cmp(string a, string b)
{
    return cal(a+b)>cal(b+a);
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    string t;
    for(int i = 0; i < n; i++)t += s[i];
    printf("%lld\n", cal(t));
	return 0;
}

