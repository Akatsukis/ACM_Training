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
vector<int> prime{3, 5, 7, 11, 13, 16, 17};
int rem[20], mod[20];
void gcd(int a, int b, int &d, int &x, int &y)
{
    if(b == 0){
        d = a;
        x = 1,y = 0;
    }
    else{
        gcd(b, a%b, d, y, x);
        y -= (a/b)*x;
    }
}

int China(int n, int *m, int *a)
{
    int M = 1, d ,y ,x = 0;
    for(int i = 0; i < n; i++) M *= mod[i];
    for(int i = 0; i < n; i++){
        int w = M/mod[i];
        gcd(mod[i], w, d, d, y);
        x = (x+y*w*rem[i])%M;
    }
    return (x+M)%M;
}

int main()
{
    int T, n, m;
    scanf("%d%d%d", &T, &n, &m);
    while(T--){
        for(int i = 0; i < min(n, (int)prime.size()); i++){
            mod[i] = prime[i], rem[i] = 0;
            for(int j = 0; j < 18; j++){
                printf("%d%c", prime[i], " \n"[j==17]);
            }
            fflush(stdout);
            for(int j = 0; j < 18; j++){
                int x; sc(x);
                rem[i] = (rem[i]+x)%mod[i];
            }
        }
        int ans = China(min(n, (int)prime.size()), mod, rem);
        printf("%d\n", ans);
        fflush(stdout);
        scanf("%*d");
    }
    return 0;
}

