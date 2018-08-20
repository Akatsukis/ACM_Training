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
string s, t;

int main()
{
    fastio;
    int n, k;
    cin >> n >> k >> s;
    int cnt = 0, l = 0;
    for(int i = 0; i < SZ(s); i++){
        if(s[i] == '('){
            if(l < k/2)t.pb(s[i]), cnt++, l++;
        }
        else{
            if(cnt)t.pb(s[i]), cnt--;
        }
        if(SZ(t) == k)break;
    }
    cout << t << endl;
    return 0;
}


