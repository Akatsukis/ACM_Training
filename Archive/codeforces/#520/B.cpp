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
int n;

int main()
{
    sc(n);
    vector<int> vec, val;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            int now = 0;
            while(n%i == 0){
                now++;
                n /= i;
            }
            vec.pb(now);
            val.pb(i);
        }
    }
    if(n != 1){
        vec.pb(1); val.pb(n);
    }
    int ans1 = 1, ans2 = 0, mx = 0;
    for(auto v : val)ans1 *= v;
    for(auto v : vec)mx = max(mx, v);
    bool mul = 0;
    for(auto v : vec){
        if(v != mx){
            mul = 1;
            break;
        }
    }
    for(auto v : vec){
        while(v%2 == 0)v /= 2;
        if(v != 1)mul = 1;
    }
    if(mul)ans2++;
    for(int i = 0; (1<<i) < mx; i++)ans2++;
    printf("%d %d\n", ans1, ans2);
    return 0;
}

