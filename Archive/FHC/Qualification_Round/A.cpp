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
const int maxn = 100;
string s[maxn];
int val[maxn];

int main()
{
    int T, kase = 1;
    cin >> T;
    while(T--){
        memset(val, 0, sizeof(val));
        int n;
        ll k, v;
        cin >> n >> k >> v;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        int st = k*(v-1)%n;
        vector<string> ans;
        for(int i = 0; i < k; i++){
            val[(st+i)%n]++;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < val[i]; j++)ans.pb(s[i]);
        }
        cout << "Case #" << kase++ << ":";
        for(auto t : ans)cout << " " << t;
        cout << endl;
    }
    return 0;
}

