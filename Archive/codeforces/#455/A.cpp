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
    string a, b;
    cin >> a >> b;
    string c = a+b;
    string ans;
    for(int j = 1; j <= (int)a.size(); j++){
        for(int l = 1; l <= (int)b.size(); l++){
            if(ans.size() == 0 || ans > a.substr(0, j)+b.substr(0, l))
                ans = a.substr(0, j)+b.substr(0, l);
        }
    }
    cout << ans << endl;
    return 0;
}

