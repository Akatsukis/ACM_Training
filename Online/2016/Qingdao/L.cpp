#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 51;
bool ok[maxn][maxn][maxn];
bitset<88> bs[11];
int a[maxn];
int b[3];
int n, q;

bool solve(int x, int y, int z)
{
    for(int i = 0; i <= 10; i++)bs[i].reset();
    bs[0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(i == x || i  == y || i == z)continue;
        for(int j = 10; j >= 1; j -= 2) {
            bs[j] |= bs[j-1]<<a[i];
            bs[j-1] |= bs[j-2]<<a[i];
        }
    }
    return bs[10][87];
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 1; i <= n; i++)sc(a[i]);
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
                for(int k = j; k <= n; k++)
                    ok[i][j][k] = solve(i, j, k);
        sc(q);
        for(int i = 0; i < q; i++){
            for(int j = 0; j < 3; j++)sc(b[j]);
            sort(b, b+3);
            if(ok[b[0]][b[1]][b[2]])printf("Yes\n");
            else printf("No\n");
        }
        
    }
    return 0;
}

