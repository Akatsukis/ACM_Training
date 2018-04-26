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
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int mp[maxn][maxn];
struct atom
{
    pii id;
    int x;
}ans[maxn][maxn];

int main()
{
    int n, k;
    sc(n); sc(k);
    k--;
    for(int i = 1; i <= n; i++){
        char s[maxn];
        scanf("%s", s+1);
        for(int j = 1; j <= n; j++){
            if(s[j] == '#')mp[i][j] = 1;
            else mp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j+k <= n; j++){
            bool flg = 1;
            for(int h = j; h <= j+k; h++){
                if(mp[i][h]){
                    flg = 0;
                    break;
                }
            }
            if(flg){
                for(int h = j; h <= j+k; h++){
                    ans[i][h].x++;
                }
            }
            flg = 1;
            for(int h = j; h <= j+k; h++){
                if(mp[h][i]){
                    flg = 0;
                    break;
                }
            }
            if(flg){
                for(int h = j; h <= j+k; h++){
                    ans[h][i].x++;
                }
            }   
        }
    }
    pii cor;
    int mx = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //printf("ans[%d][%d]=%d\n", i, j, ans[i][j].x);
            if(ans[i][j].x > mx){
                mx = ans[i][j].x;
                cor = mk(i, j);
            }
        }
    }
    printf("%d %d\n", cor.fi, cor.se);
    return 0;
}

