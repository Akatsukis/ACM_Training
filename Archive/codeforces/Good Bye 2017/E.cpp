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

const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 200;
string s[maxn];
set<string> st;

int qpow(int a, int n)
{
    int res = 1;
    while(n){
        if(n&1)res=1LL*res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int main()
{
    int m, n;
    sc(m);sc(n);
    int add = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        string tmp;
        for(int j = 0; j < m; j++){
            if(s[i][j]=='0')tmp.pb('1');
            else tmp.pb('1');
        }
        st.insert(s[i]);
        if(st.count(tmp))s[i+add] = tmp, add++;
    }
    int mx = 0;
    for(int i = 0; i < n+add; i++){
        for(int j = i+1; j < n+add; j++){
            int cnt = 0;
            for(int k = 0; k < m; k++){
                if(s[i][k]=='1'&&s[j][k]=='1')cnt++;
            }
            mx = max(mx, cnt);
        }
    }
    int ans = qpow(2, mx);
    printf("%d\n", (ans+mod)%mod);
    return 0;
}

