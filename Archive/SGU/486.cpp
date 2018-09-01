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
    string s, t;
    cin >> s >> t;
    set<char> st[2];
    int u = 0, v = 0, n = s.size();;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i])u++;
        else{
            if(st[0].count(t[i]))v++;
            if(st[1].count(s[i]))v++;
            st[0].insert(s[i]);
            st[1].insert(t[i]);
        }
    }
    printf("%d %d\n", u, v);
    return 0;
}

