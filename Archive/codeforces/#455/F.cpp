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
int ans1[maxn];
int ans2[maxn];
int n;

void solve()
{
    int n_ = 1;
    while(n_*2<=n)n_*=2;
    if(n&1){
        puts("NO");
    }
    else{
        int now = n;
        while(now != 0){
            int nxt;
            for(int i = 1; n_+i-1<=now&&n_-i>=1; i++){
                ans1[n_-i] = n_+i-1;
                ans1[n_+i-1] = n_-i;
                nxt = n_-i-1;
            }
            n_>>=1;
            now = nxt;
        }
        puts("YES");
        for(int i = 1; i <= n; i++){
            printf("%d%c", ans1[i], " \n"[i==n]);
        }
    }
    while(n_*2<=n)n_*=2;
    if(n <= 5 || n_ == n)puts("NO");
    else{
        puts("YES");
        if(n == 6)printf("3 6 2 5 1 4\n");
        else if(n == 7)printf("7 3 6 5 1 2 4\n");
        else{
            ans2[1] = 7, ans2[2] = 3, ans2[3] = 6, ans2[4] = 5, ans2[5] = 1, ans2[6] = 2, ans2[7] = 4;
            int now = 8;
            while(now <= n){
                for(int i = now; i <= 2*now-1 && i <= n; i++){
                    ans2[i] = i+1;
                    if(i == 2*now-1||i==n)ans2[i] = now;
                }
                now *= 2;
            }
            for(int i = 1; i <= n; i++){
                printf("%d%c", ans2[i], " \n"[i==n]);
            }
        }
    }
}

int main()
{
    sc(n);
    solve();
    return 0;
}

