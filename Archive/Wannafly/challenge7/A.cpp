#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int n, m, l, r, k, T;
    cin >> T;
    while(T--){
        cin >> n >> m >> l >> r >> k;
        int x[4], y[4];
        x[0] = l-1, y[0] = r-1;
        x[1] = n-l, y[1] = r-1;
        x[2] = l-1, y[2] = m-r;
        x[3] = n-l, y[3] = m-r;
        ll ans = 0;
        bool flag = 1;
        for(int i = 0; i < 4; i++){
            if(x[i] == 0 || y[i] == 0)continue;
            if(k > x[i] || k > y[i]){
                flag = 0;
                break;
            }
            ans += 1LL*((x[i]-1)/k+1)*((y[i]-1)/k+1);
        }
        if(flag)cout << ans << endl;
        else printf("-1\n");
    }

    return 0;
}

