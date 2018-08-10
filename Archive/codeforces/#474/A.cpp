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
    int a = 0, b = 0, c = 0;
    bool flg = 1;
    int t = 0;
    for(auto u : s){
        if(u == 'a' && t != 0 && t != 1)flg = 0;
        if(u == 'b' && t != 1 && t != 2)flg = 0;
        if(u == 'c' && t != 2 && t != 3)flg = 0;
        if(u == 'a')a++, t = 1;
        else if(u == 'b')b++, t = 2;
        else c++, t = 3;
    }
    if(flg && t == 3 && (c == a || c == b))puts("YES");
    else puts("NO");
    return 0;
}


