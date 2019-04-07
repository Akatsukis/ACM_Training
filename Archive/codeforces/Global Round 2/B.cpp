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

int main()
{
    int n, h;
    scanf("%d%d", &n, &h);
    vector<int> vec(n, 0);
    for(auto &u :vec)sc(u);
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> all;
        for(int j = 0; j <= i; j++)all.pb(vec[j]);
        sort(ALL(all));
        int cur = 0;
        if((i+1)%2 == 0){
            for(int j = 1; j <= i; j += 2)cur += all[j];
        }
        else{
            for(int j = 0; j <= i; j += 2)cur += all[j];
        }
        if(cur <= h)ans = i+1;
        else break;
    }
    printf("%d\n", ans);
    return 0;
}

