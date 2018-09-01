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
    int n; sc(n);
    for(int i = 0;i < n; i++){
        string s;
        cin >> s;
        int t = s.size();
        if(s.substr(t-2, 2) == "ch" || s[t-1] == 'x' || s[t-1] == 's' || s[t-1] == 'o')s += "es";
        else if(s[t-1] == 'f')s[t-1] = 'v', s += "es";
        else if(s.substr(t-2, 2) == "fe")s[t-2] = 'v', s += "s";
        else if(s[t-1] == 'y')s[t-1] = 'i', s += "es";
        else s += "s";
        cout << s << endl;
    }
    return 0;
}

