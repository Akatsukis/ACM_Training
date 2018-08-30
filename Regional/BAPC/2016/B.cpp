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

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    for(int i = 0; i < n; i++){
        if(i+2 < n && s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2])ans += "C", i += 2;
        else if(s[i] == 'R')ans += "S";
        else if(s[i] == 'B')ans += "K";
        else if(s[i] == 'L')ans += "H";
    }
    cout << ans << endl;
    return 0;
}


