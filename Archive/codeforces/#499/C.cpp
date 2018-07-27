#include <bits/stdc++.h>
using namespace std;
#define double long double 
const double eps = 1e-10;
const int maxn = 1e5+10;
double a[maxn], b[maxn];
int n, k;

bool check(double m)
{
    bool flg = 1;
    double now = m+k;
    for(int i = 0; i < n; i++){
        double diff = now/a[i];
        now -= diff;
        if(now < k){
            flg = 0;
            break;
        }
        diff = now/b[(i+1)%n];
        now -= diff;
        if(now < k){
            flg = 0;
            break;
        }
    }
    return flg;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)scanf("%Lf", &a[i]);
    for(int i = 0; i < n; i++)scanf("%Lf", &b[i]);
    double l = 0, r = 2e9, ans = -1;
    while(l+eps <= r){
        double m = (l+r)/2;
        if(check(m)){
            ans = m;
            r = m-eps;
        }
        else l = m+eps;
    }
    if(ans < 0)printf("-1\n");
    else printf("%.10Lf\n", ans);
}
