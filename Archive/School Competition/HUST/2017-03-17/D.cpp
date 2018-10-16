#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ALL(A) A.begin(),A.end()
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n", x)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100;
int R;
char s[maxn][maxn];

bool ok(int x, int y)
{
    return Abs((sqr(x-(R))+sqr(y-(R))-sqr(R))) <= 3;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(s, 0, sizeof(s));
        sc(R);
        for(int i = 0; i < 2*R+1; i++){
            for(int j = 0; j < 2*R+1; j++){
                //printf("x=%d, y=%d\n", i, j);
                if(ok(i, j))s[i][j] = '*';
                else s[i][j] = ' ';
            }
        }
        printf("Case %d:\n", kase++);
        for(int i = 0; i < 2*R+1; i++){
            printf("%s\n", s[i]);
        }
    }
    return 0;
}
