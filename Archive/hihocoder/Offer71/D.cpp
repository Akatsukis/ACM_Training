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
const int maxn = 2e5+10;
char t[maxn];
int ma[maxn];
string s;
int n;

int manacher()
{
    memset(ma, 0 ,sizeof(ma));
    memset(t, 0, sizeof(t));
    t[0] = '$', t[1] = '#';
    for(int i = 0; i < n; i++)t[i*2+2] = s[i], t[i*2+3] = '#';
    int mx = -1, ctr = -1, ret = 1;
    for(int i = 1; i < 2*n+2; i++){
        if(mx > i)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(t[i-ma[i]] == t[i+ma[i]])ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
        ret = max(ret, ma[i]-1);
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        int ans = 0;
        while(1){
            n = s.size();
            manacher();
            int from = -1, mx = 0;
            for(int i = 3; i < 2*n; i += 2){
                if(ma[i]-1 >= mx){
                    //printf(">>pos=%d, mx=%d\n", i, ma[i]-1);
                    mx = ma[i]-1;
                    from = i/2-(mx/2);
                }
            }
            //printf("from=%d, len=%d\n", from, mx);
            if(mx == 0){
                ans += n;
                break;
            }
            else{
                //printf("n=%d, mx=%d\n", n, mx);
                s = s.substr(from, mx/2);
                //cout << s << endl;
                ans = ans+(n-mx)+1;
                //printf("ans=%d\n", ans);
            }   
        }
        cout << ans << endl;
    }
    return 0;
}


