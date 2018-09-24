/*
ID:dreanda3
LANG:C++
TASK:palsquare
*/
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
const int maxn = 1e4+10;
int bit[maxn];

vector<char> enc(int a, int base)
{
    vector<char> re;
    while(a){
        if(a%base < 10)re.pb(a%base+'0');
        else re.pb(a%base-10+'A');
        a /= base;
    }   
    reverse(ALL(re));
    return re;
}

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int b; sc(b);
    int n = 300;
    for(int i = 1; i <= n; i++){
        int j = i*i;
        vector<char> s = enc(i, b);
        vector<char> t = enc(j, b);
        vector<char> q = t;
        reverse(ALL(q));
        if(q == t){
            for(auto u : s)printf("%c", u);
            putchar(' ');
            for(auto u : t)printf("%c", u);
            putchar('\n');
        }
    }
    return 0;
}

