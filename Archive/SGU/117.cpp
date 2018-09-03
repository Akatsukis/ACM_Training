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
map<int, int> mp[2];

int main()
{
    int n, m, k;
    sc(n); sc(m); sc(k);
    for(int i = 2; i*i <= k; i++){
        while(k%i == 0){
            mp[0][i]++;
            k /= i;
        }
    }
    if(k != 1)mp[0][k]++;
    int ans = 0;
    for(int i = 0; i < n; i++){
        mp[1].clear();
        int x; sc(x);
        for(int j = 2; j*j <= x; j++){
            while(x%j == 0){
                mp[1][j]++;
                x /= j;
            }
        }
        if(x != 1)mp[1][x]++;
        bool flg = 1;
        for(auto p : mp[0]){
            if(mp[1][p.fi]*m < p.se){
                flg = 0;
                break;
            }
        }
        ans += flg;
    }
    printf("%d\n", ans);
    return 0;
}

