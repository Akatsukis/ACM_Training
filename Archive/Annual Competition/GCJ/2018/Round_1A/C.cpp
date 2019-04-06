#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pdd pair<double ,double>
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
const int maxn = 110;
double W[maxn], H[maxn];
pdd p[maxn];
bool del[maxn];
int n;
double P;

double cmp(const pdd &a, const pdd &b)
{
    if(a.fi != b.fi)return a.fi > b.fi;
    else return a.se > b.se;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(del, 0, sizeof(del));
        scanf("%d%lf", &n, &P);
        double now = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf", &W[i], &H[i]);
            now += 2*(W[i]+H[i]);
            p[i].fi = min(W[i], H[i]);
            p[i].se = 2*sqrt(sqr(W[i])+sqr(H[i]));
        }
        sort(p+1, p+n+1, cmp);
        double tmp = 0;
        for(int i = 1; i <= n; i++){
            double rem = P-now;
            for(int j = 1; j <= n; j++){
                if(!del[j] && (p[j].fi>=rem-tmp || p[j].se <= rem)){
                    del[j] = 1;
                    now = P;
                    break;
                }
            }
            if(fabs(now-P) < eps)break;
            for(int j = 1; j <= n; j++){
                if(del[j])continue;
                else if(p[j].fi > rem-tmp)del[j] = 1;
                else{
                    del[j] = 1;
                    now += p[j].se;
                    tmp += p[j].se - p[j].fi;
                    break;
                }
            }   
        }
        printf("Case #%d: %.10f\n", kase++, now);
    }
    return 0;
}

