#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define debug cout<<"???"<<endl
const double eps = 1e-8;
const int maxn = 2e5+10;
int h[maxn], u[maxn], d[maxn];
int a[maxn], b[maxn];
double mn[maxn], mx[maxn];
int n, m;

bool check(double mid)
{
    for(int i = 1; i <= n; i++){
        mn[i] = h[i]-mid;
        mx[i] = h[i]+mid;
        mn[i] = max(mn[i], 0.0);
    }
    //for(int i = 1; i <= n; i++){
        //printf("%f, %f\n", mn[i], mx[i]);
    //}
    //cout << ">>>" << endl;
    for(int i = 1; i <= m; i++){
        if(b[i] > a[i]){
            for(int j = a[i]+1; j <= b[i]; j++){
                mx[j] = min(mx[j], mx[j-1]+u[i]);
                mn[j] = max(mn[j], mn[j-1]-d[i]);
            }
        }
        if(b[i] < a[i]){
            for(int j = a[i]-1; j >= b[i]; j--){
                mx[j] = min(mx[j], mx[j+1]+u[i]);
                mn[j] = max(mn[j], mn[j+1]-d[i]);
            }
        }

    }
    //for(int i = 1; i <= n; i++){
        //printf("%f, %f\n", mn[i], mx[i]);
    //}
    for(int i = 1; i <= n; i++)if(mn[i] > mx[i])return 0;
    return 1;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int w, x, y, z;
        scanf("%d%d%d%d%d%d%d%d", &n, &m, &h[1], &h[2], &w, &x, &y, &z);
        for(int i = 1; i <= m; i++)scanf("%d%d%d%d", &a[i], &b[i], &u[i], &d[i]);
        for(int i = 3; i <= n; i++)h[i] = (1LL*w*h[i-2]+1LL*x*h[i-1]+y)%z;
        //for(int i = 1; i <= n; i++)printf("h[%d]=%d\n", i, h[i]);
        double l = 0, r = 2e6, ans = 0;
        while(l+eps < r){
            double mid = (l+r)/2;
            //printf("mid=%f\n", mid);
            fflush(stdout);
            if(check(mid)){
                ans = mid;
                r = mid-eps;
            }
            else l = mid+eps;
        }
        printf("Case #%d: %.7f\n", kase++, ans);
    }
}
