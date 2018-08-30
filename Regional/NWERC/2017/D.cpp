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
const int maxn = 30;
map<string, string> flt;
map<string, int> mp[2];
string stn[maxn];

int main()
{
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++)cin >> stn[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string s, t, q;
        cin >> s >> t >> q;
        flt[s] = t;
        if(q[0] == 'c')mp[0][s]++;
        else mp[1][s]++;
    }
    bool crt = 1;
    ll tot = 1, crr = 1;
    for(int i = 0; i < n; i++){
        int u = mp[0][stn[i]], v = mp[1][stn[i]];
        if(v)crt = 0;
        tot *= u+v;
        crr *= u;
    }
    if(tot == 1){
        for(int i = 0; i < n; i++)cout << flt[stn[i]] << " \n"[i==n-1];
        cout << (crt?"correct":"incorrect") << endl;
    }
    else{
        cout << crr <<" correct" << endl;
        cout << tot-crr << " incorrect" << endl;
    }
    return 0;
}


