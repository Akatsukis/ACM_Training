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
    int cnt = 0;
    bool flg = 1;
    if(s[0] != 'A')flg = 0;
    for(int i = 1; i < n; i++){
        if(isupper(s[i])){
            if(s[i] == 'C' && i >= 2 && i <= n-2)cnt++;
            else flg = 0;
        }
    }
    if(cnt != 1)flg = 0;
    if(flg)puts("AC");
    else puts("WA");
    return 0;
}


