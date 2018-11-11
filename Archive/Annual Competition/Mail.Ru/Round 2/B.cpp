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
const int maxn = 1e5+10;
ll a[maxn];
int n, m, l;

int main()
{
    scanf("%d%d%d", &n, &m, &l);
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
    int ans = 0;
    for(int i = 1; i <= n;){
        if(a[i] > l){
            int j = 1;
            while(i+j <= n && a[i+j] > l)j++;
            ans++;
            i += j;
        }
        else i++;
    }
    for(int i = 0; i < m; i++){
        int t; sc(t);
        if(t == 0)printf("%d\n", ans);
        else{
            int pos, x;
            sc(pos); sc(x);
            if(a[pos] > l)a[pos] += x;
            else{
                a[pos] += x;
                if(a[pos] > l){
                    ans++;
                    if(a[pos-1] > l)ans--;
                    if(a[pos+1] > l)ans--;
                }
            }
        }
    }
    return 0;
}

