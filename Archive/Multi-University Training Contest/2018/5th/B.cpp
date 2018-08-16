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
const int INF = 0x3f3f3f3f;
const int maxn = 10;
string s, mn, mx;
int n, k;

void get_min(string t, int pos, int stp)
{
    if(pos == n || stp == k){
        mn = min(mn, t);
        return;
    }
    bool flg = 1;
    for(int i = pos+1; i < n; i++){
        if(!pos && t[i] == '0')continue;
        if(t[i] < t[pos]){
            string tmp = t;
            string nxt = t;
            swap(tmp[pos], tmp[i]);
            get_min(tmp, pos+1, stp+1);
            flg = 0;
        }
    }
    if(flg)get_min(t, pos+1, stp);
}

void get_max(string t, int pos, int stp)
{
    if(pos == n || stp == k){
        mx = max(mx, t);
        return;
    }
    bool flg = 1;
    for(int i = pos+1; i < n; i++){
        if(t[i] > t[pos]){
            string tmp = t;
            string nxt = t;
            swap(tmp[pos], tmp[i]);
            get_max(tmp, pos+1, stp+1);
            flg = 0;
        }
    }
    if(flg)get_max(t, pos+1, stp);
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> s >> k;
        n = s.length();
        mn = mx = s;
        get_min(mn, 0, 0);
        get_max(mx, 0, 0);
        cout << mn << " " << mx << endl;
    }
    return 0;
}


