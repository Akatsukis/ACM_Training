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
const int maxn = 5e3+10;
int a[maxn];
map<int, double> mp[maxn*4];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    sort(a+2, a+1+n);
    int k = 1;
    while(k < n)k *= 2;
    int id = k;
    for(int i = 1; i <= n; i++){
        //printf("id=%d\n", id);
        mp[id][i] = 1.0;
        if(2*k-id-1 > n-i)id += 2;
        else id++;
    }
    for(int i = k-1; i >= 1; i--){
        if(!mp[i*2+1].size())mp[i] = mp[i*2];
        else{
            for(auto u : mp[i*2]){
                for(auto v : mp[i*2+1]){
                    double tmp = u.se*v.se;
                    double p = a[u.fi], q = a[v.fi];
                    //printf("(%d,%d) %f %f %f\n", u.fi, v.fi, p, q, tmp);
                    mp[i][u.fi] += tmp*p/(p+q);
                    mp[i][v.fi] += tmp*q/(p+q);
                }
            }
        }
    }
    printf("%.10f\n", mp[1][1]);
    return 0;
}


