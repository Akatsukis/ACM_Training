#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
template<class T>T gcd(T a, T b){if(!b)return a; return gcd(b,a%b);}
const int maxn = 10;
int a[maxn];
int b[maxn];
int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        sc(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        for(int i = 0; i < n; i++)sc(b[i]);
        int p = b[n-1], q = a[n-1];
        int d = gcd(p, q);
        p /= d, q /= d;
        for(int i = n-2; i >= 0; i--){
            p = a[i]*q+p;
            q = b[i]*q;
            swap(p, q);
            d = gcd(p, q);
            p /= d, q /= d;
        }
        printf("Case #%d: %d %d\n", kase++, p, q);
    }
}
