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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
string s;

int main()
{
    int n, x, y;
    cin >> n >> x >> y >> s;
    ll ans = 0, cnt = 0;
    for(int i = 0; i < n; ){
        if(s[i] == '1'){
            i++;
            continue;
        }
        int j = 1;
        while(i+j < n && s[i+j]=='0')j++;
        i += j;
        cnt++;
    }
    if(!cnt)ans = 0;
    else ans = (cnt-1)*min(x, y)+y;
    cout << ans << endl;
    return 0;
}

