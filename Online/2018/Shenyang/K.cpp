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
int tb[20] = {2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 53, 71, 73, 113, 131, 137, 173, 311, 317};
const int maxn = 200;
char s[maxn];

int main()
{
    int T, kase = 1; 
    sc(T);
    while(T--){
        scanf("%s", s);
        int n = strlen(s);
        printf("Case #%d: ", kase++);
        if(n > 3)printf("%d\n", tb[18]);
        else{
            int val = 0;
            for(int i = 0; i < n; i++){
                val = val*10+s[i]-'0';
            }
            if(val >= 317){
                printf("%d\n", tb[18]);
                continue;
            }
            for(int i = 1; i < 19; i++){
                if(tb[i-1] <= val && tb[i] > val){
                    printf("%d\n", tb[i-1]);
                    break;
                }
            }
        }
    }
    return 0;
}

