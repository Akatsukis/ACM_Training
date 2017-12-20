#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int h[maxn];

int main()
{
    int n;
    sc(n);
    int flag = 0;
    for(int i = 0; i <= n; i++){
        sc(h[i]);
    }
    for(int i = 0; i <= n; i++){
        if(i + 1 <= n && h[i] > 1 && h[i+1] > 1)flag = i+1;
    }
    if(!flag)printf("perfect\n");
    else{
        printf("ambiguous\n");
        int now = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < h[i]; j++){
                printf("%d ", now);
            }
            now += h[i];
        }
        printf("\n");
        now = 0;
        for(int i = 0; i <= n; i++){
            if(i == flag){
                printf("%d ", now-1);
                for(int j = 1; j < h[i]; j++){
                    printf("%d ", now);
                }
            }
            else{
                for(int j = 0; j < h[i]; j++){
                    printf("%d ", now);
                }
            }
            now += h[i];
        }
        printf("\n");
    }
    return 0;
}

