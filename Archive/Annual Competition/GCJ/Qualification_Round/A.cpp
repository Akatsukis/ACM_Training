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
ll d;
map<string, ll> mp;

ll calc(string s)
{
    int n = s.size(), now = 1, ret = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'S')ret += now;
        else now *= 2;
    }
    return ret;
}

int solve(string s)
{
    int ret = -1;
    queue<string> q;
    q.push(s);
    mp[s] = 0;
    while(!q.empty()){
        string t = q.front(); q.pop();
        if(calc(t) <= d)return mp[t];
        for(int i = 1; i < (int)t.size(); i++){
            string ns = t;
            if(ns[i] == 'S' && ns[i-1] == 'C'){
                swap(ns[i], ns[i-1]);
                if(!mp.count(ns)){
                    q.push(ns);
                    mp[ns] = mp[t]+1;
                }
            }   
        }
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        mp.clear();
        string s;
        cin >> d >> s;
        int ans = solve(s);
        if(ans != -1)printf("Case #%d: %d\n", kase++, ans);
        else printf("Case #%d: Impossible\n", kase++);
    }
    return 0;
}

