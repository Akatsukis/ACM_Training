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
const int maxn = 1e5+10;
string s, t;

int main()
{
    int n, m;
    cin >> n >> m >> s >> t;
    int pos = -1;
    for(int i = 0; i < n; i++)if(s[i] == '*'){
        pos = i;
        break;
    }
    if(pos == -1){
        if(s == t)puts("YES");
        else puts("NO");
        return 0;
    }
    int u = pos, v = n-pos-1;
    if(m-v >= u && s.substr(0, u) == t.substr(0, u) && s.substr(u+1, v) == t.substr(m-v, v))puts("YES");
    else puts("NO");
    return 0;
}


