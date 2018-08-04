#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
typedef long long ll;
using namespace std;
const int maxn = 22;
int a[maxn], L;
int mat[maxn][maxn];

int sum(int u1, int v1, int u0, int v0)
{
    u1 = (u1+L)%L, v1 = (v1+L)%L, u0= (u0+L)%L, v0 = (v0+L)%L;
    return mat[u1+1][v1+1]-mat[u0][v1+1]-mat[u1+1][v0]+mat[u0][v0];
}

int main()
{
    int T; sc(T);
    while(T--){
        memset(mat, 0, sizeof(mat));
        sc(L);
        for(int i = 0; i < L; i++)sc(a[i]);
        L *= 2;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < L; j++){
                mat[i+1][j+1] = a[((i+j)*(i+j+1)/2+i)%(L/2)];
            }
        }
        for(int i = 0; i < L; i++){
            for(int j = 0; j < L; j++){
                mat[i+1][j+1] += mat[i][j+1]+mat[i+1][j]-mat[i][j];
            }
        }
        int q; sc(q);
        for(int i = 0; i < q; i++){
            int x0, y0, x1, y1;
            ll ans = 0;
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            ll l0 = (x0+L)/L*L, r0 = (y0+L)/L*L;
            ll l1 = x1/L*L, r1 = y1/L*L;
            ll u = (l1-l0)/L, v = (r1-r0)/L;
            ans += sum(l0-1, r0-1, x0, y0);
            ans += sum(l0-1, r1-1, x0, r0)*v;
            ans += sum(l0-1, y1, x0, r1);
            ans += sum(l1-1, r0-1, l0, y0)*u;
            ans += sum(l1-1, r1-1, l0, r0)*u*v;
            ans += sum(l1-1, y1, l0, r1)*u;
            ans += sum(x1, r0-1, l1, y0);
            ans += sum(x1, r1-1, l1, r0)*v;
            ans += sum(x1, y1, l1, r1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
