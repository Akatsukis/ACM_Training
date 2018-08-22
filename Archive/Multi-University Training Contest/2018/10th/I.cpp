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
const int maxn = 100;
int ans[maxn];
const int MAX = 2e7+10;
int pnum,p[MAX],mob[MAX],noprime[MAX],facnum[MAX],d[MAX],phi[MAX];
void get_all()
{
    pnum = 0;
    phi[1] = 1;
    mob[1] = 1;
    facnum[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        if(!noprime[i])
        {
            phi[i] = i - 1;
            mob[i] = -1;
            p[pnum ++] = i;   
            facnum[i] = 2;  
            d[i] = 1;      
        }
        for(int j = 0; j < pnum && i * p[j] < MAX; j++)
        {
            noprime[i * p[j]] = true;
            if(i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j];
                mob[i * p[j]] = 0;
                facnum[i * p[j]] = facnum[i] / (d[i] + 1) * (d[i] + 2); 
                d[i * p[j]] = d[i] + 1; 
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            mob[i * p[j]] = -mob[i];
            facnum[i * p[j]] = facnum[i] * 2;
            d[i * p[j]] = 1; 
        }
    }
}
int main()
{
    get_all();
    for(int n = 1; n < maxn; n++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                ans[n] += (gcd(i+j, i-j) == 1);
            }
        }
        printf("ans[%d]=%d, phi[%d]=%d\n", n, ans[n], n, phi[n]);
    }
    return 0;
}


