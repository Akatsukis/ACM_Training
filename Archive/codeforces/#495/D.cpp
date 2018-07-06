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
#define Abs(x) ((x)>=0?(x):(-(x)))
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
int a[maxn];
int b[maxn];

int main()
{
    int n;
    sc(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x; sc(x);
        mx = max(mx, x);
        a[x]++;
    }
    int gap = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != i*4){
            gap = i;
            break;
        }
    }
    vector<pii> vec;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0)vec.pb(mk(i, n/i));
    }
    for(auto p : vec){
        int row = p.fi, col = p.se;
        int ansx = gap, ansy = row+col-mx-ansx;
        if(ansx <= 0 || ansx > row || ansy <= 0 || ansy > col)continue;
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                int dis = Abs(i-ansx)+Abs(j-ansy);
                b[dis]++;
            }
        }
        bool flg = 1;
        for(int i = 0; i <= mx; i++){
            if(a[i] != b[i]){
                flg = 0;
                break;
            }   
        }
        if(flg){
            printf("%d %d\n%d %d\n", row, col, ansx, ansy);
            return 0;
        }
    }
    for(auto p : vec){
        int row = p.fi, col = p.se;
        int ansy = gap, ansx = row+col-mx-ansy;
        if(ansx <= 0 || ansx > row || ansy <= 0 || ansy > col)continue;
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                int dis = Abs(i-ansx)+Abs(j-ansy);
                b[dis]++;
            }
        }
        bool flg = 1;
        for(int i = 0; i <= n; i++){
            if(a[i] != b[i]){
                flg = 0;
                break;
            }   
        }
        if(flg){
            printf("%d %d\n%d %d\n", row, col, ansx, ansy);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

