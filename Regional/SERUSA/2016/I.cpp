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
string s;
int n;

bool ok(string u, string v)
{
    int m = u.size();
    for(int i = 0; i < m; i++){
        if(u[i] != v[(i+1)%m])return 0;
    }
    return 1;
}

bool check(int len)
{
    for(int i = 0; i+len < n; i += len){
        if(!ok(s.substr(i, len), s.substr(i+len, len)))return 0;
    }
    return 1;
}

int main()
{
    cin >> s;
    n = s.size();
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0 && check(i)){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
