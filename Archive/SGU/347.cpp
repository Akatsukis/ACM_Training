#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 100;
string s[maxn];

bool cmp(string a, string b)
{
    return a+b < b+a;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> s[i];
    sort(s, s+n, cmp);
    string ans;
    for(int i = 0; i < n; i++)ans += s[i];
    cout << ans << endl;
    return 0;
}

