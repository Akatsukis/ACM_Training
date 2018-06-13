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
const int maxn = 128;
long double f[maxn][maxn];
map<int, long double> mp[maxn];

int main()
{
    for(int i = 1; i <= 16; i++){
        for(int j = 1; j <= 16; j++)scanf("%Lf", &f[i][j]);
        mp[i+15][i] = 1;
    }
    for(int i = 15; i >= 1; i--){
        for(auto u : mp[i*2]){
            for(auto v : mp[i*2+1]){
                mp[i][u.fi] += u.se*v.se*f[u.fi][v.fi];
            }
        }
        for(auto u : mp[i*2+1]){
            for(auto v : mp[i*2]){
                mp[i][u.fi] += u.se*v.se*f[u.fi][v.fi];
            }
        }
    }
    int i = 0;
    for(auto u : mp[1]){
        printf("%.10Lf%c", u.se, " \n"[i==15]);
        i++;
    }
    return 0;
}

