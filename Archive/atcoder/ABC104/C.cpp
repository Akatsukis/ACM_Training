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
const int INF = 0x3f3f3f3f;
const int maxn = 20;
int p[maxn], c[maxn];

int main()
{
    int n, k;
    sc(n); sc(k);
    for(int i = 1; i <= n; i++){
        sc(p[i]); sc(c[i]);
    }
    int ans = INF;
    vector<int> vec;
    for(int i = 1; i <= n; i++)vec.pb(i);
    do{
        int now = k, tot = 0;
        for(int i = 0; i < n; i++){
            int add = min(p[vec[i]], (now-1+vec[i]*100)/(100*vec[i]));
            //printf("add=%d\n", add);
            now -= add*100*vec[i];
            tot += add;
            //printf("tot=%d\n", tot);
            if(add == p[vec[i]])now -= c[vec[i]];
            if(now < 0)break;
        }
        ans = min(ans, tot);
    }while(next_permutation(ALL(vec)));
    printf("%d\n", ans);
    return 0;
}


