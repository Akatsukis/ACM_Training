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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e5+10;
int a[maxn];
ll pre[maxn];
int n, t;

int main()
{
    sc(n);
    t = 1;
    for(int i = 0; i < n; i++){
        int p;
        sc(p);
        if(p == 1){
            int q;
            sc(q);
            a[t] = q;
            pre[t] = pre[t-1] + a[t];
            t++;
        }
        else{
            double l = 0, r = 1e9, ans = 0;
            while(l < r + eps){
                double m = (l+r)/2;
                int u = 1, v = t-2, pos = 1;
                while(u <= v){
                    int w = (u+v)/2;
                    if(a[w] <= m){
                        pos = w;
                        u = w + 1;
                    }
                    else v = w - 1;
                }
                double avg = 1.0*(a[t-1]+pre[pos])/(pos+1);
                //printf("m=%f, pos=%d\n", m, pos);
                if(avg <= m){
                    ans = m;
                    r = m - eps;
                }
                else l = m + eps;
            }
            printf("%.7f\n", a[t-1]-ans+eps);
        }
    }
    return 0;
}

