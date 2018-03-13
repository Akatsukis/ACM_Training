#include <cstdio>
#include <cmath>
using namespace std;
#define ull unsigned long long
ull pow2[65];

void init()
{
    pow2[0] = 1;
    for(int i = 1; i < 64; i++){
        pow2[i] = pow2[i-1] * 2;
    }
}

double dfs(int r, ull k, double p)
{
    //printf("dfs(%d,%llu,%f)\n", r, k, p);
    if(k == pow2[r]){
        return pow(p,r-1);
    }
    else if(k == pow2[r-1]){
        return pow(p,r-1)*(1-p);
    }
    else if(k > pow2[r-1]){
        double tmp = dfs(r-1, k-pow2[r-1], p);
        double res = pow(p,r-1)*(tmp*p+(1-tmp)*(1-p));
        return res;
    }
    else{
        double tmp = dfs(r-1, k, p);
        double res = (1-p)*tmp;
        return res;
    }
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        int r;
        ull k;
        double p;
        scanf("%d%llu%lf", &r, &k, &p);
        if(p < 0.5){
            p = 1.0 - p;
            k = pow2[r] - k + 1;
        }
        k = pow2[r] - k + 1;
        double ans = dfs(r, k, p);
        printf("%f\n", ans);
    }
    return 0;
}
