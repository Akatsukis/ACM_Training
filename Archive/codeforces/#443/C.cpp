#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fst fi
#define scd se
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e5+10;
char s[maxn][2];
int d[maxn];
int dp[20];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%s%d", s[i], &d[i]);
    }
    int Xor = 0, Or = 0;
    for(int i = 0; i < 10; i++){
        int a = 0, b = 1;
        for(int j = 0; j < n; j++){
            int now = (d[j] >> i) & 1;
            if(s[j][0] == '^'){
                a ^= now;
                b ^= now;
            }
            if(s[j][0] == '&'){
                a &= now;
                b &= now;
            }
            if(s[j][0] == '|'){
                a |= now;
                b |= now;
            }
        }
        //printf("a=%d b=%d\n", a, b);
        if(a == 1 && b == 1){
            Or |= (1 << i);
        }
        if(a == 0 && b == 0){
            Or |= (1 << i);
            Xor |= (1 << i);
        }
        if(a == 1 && b == 0){
            Xor |= (1 << i);
        }
    }
    printf("2\n");
    printf("| %d\n", Or);
    printf("^ %d\n", Xor);
    return 0;
}


