#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    string ans;
    bool flg = 0;
    int cnt = 0;
    for(auto c : s){
        if(c == '1')flg = 1;
        if(c == '0')cnt++;
    }
    if(!flg){
        ans = "0";
    }
    else{
        ans.pb('1');
        for(int i = 0; i < cnt; i++)ans.pb('0');
    }
    cout << ans << endl;
    return 0;
}

