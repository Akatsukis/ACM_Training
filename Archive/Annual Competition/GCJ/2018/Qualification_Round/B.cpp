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
vector<int> v1, v2, v;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        v1.clear(), v2.clear(), v.clear();
        int n;
        sc(n);
        for(int i = 0; i < n; i++){
            int x;
            sc(x);
            if(i%2==0)v1.pb(x);
            else v2.pb(x);
        }
        sort(ALL(v1)), sort(ALL(v2));
        for(int i = 0, j = 0; i < (int)v1.size(); i++, j++){
            v.pb(v1[i]);
            if(j < (int)v2.size())v.pb(v2[i]);
        }
        int ans = -1;
        for(int i = 0; i < (int)v.size()-1; i++){
            if(v[i] > v[i+1]){
                ans = i;
                break;
            }
        }
        if(ans == -1)printf("Case #%d: OK\n", kase++);
        else printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

