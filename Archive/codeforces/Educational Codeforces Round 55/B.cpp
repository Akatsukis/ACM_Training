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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    vector<pii> vec;
    int cnt = 0;
    for(int i = 0, j = 1; i < n; i += j, j = 1){
        while(i+j < n && s[i+j] == s[i])j++;
        if(s[i] == 'G')vec.pb(mk(j, 0)), ans = max(ans, j), cnt++;
        else vec.pb(mk(j, 1));
    }
    if(cnt >= 2)ans++;
    bool flg = 1;
    for(int i = 0; i+2 < (int)vec.size(); i++){
        if(vec[i].se == 0 && vec[i+1].se == 1 && vec[i+2].se == 0 && vec[i+1].fi == 1){
            ans = max(ans, vec[i].fi+vec[i+1].fi+vec[i+2].fi);
            flg = 0;
        }
    }
    if(cnt == 2 && !flg)ans--;
    printf("%d\n", ans);
    return 0;
}

