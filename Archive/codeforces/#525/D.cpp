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
const int maxn = 30;

int ask(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main()
{
    int a = 0, b = 0;
    int pre = ask(a, b);
    for(int i = maxn-1; i >= 0; i--){
        if(pre == 1){
            int u = ask(a|1<<i, b);
            int v = ask(a, b|1<<i);
            if(u == v){
                a |= 1<<i;
                pre = u;
            }
            else if(u == -1 && v == 1){
                a |= 1<<i, b |= 1<<i;
            }   
        }
        else if(pre == 0){
            int u = ask(a|1<<i, b);
            int v = ask(a, b|1<<i);
            if(u == -1 && v == 1){
                a |= 1<<i, b |= 1<<i;
            }
        }
        else if(pre == -1){
            int u = ask(a|1<<i, b);
            int v = ask(a, b|1<<i);
            if(u == v){
                b |= 1<<i;
                pre = u;
            }
            else if(u == -1 && v == 1){
                a |= 1<<i, b |= 1<<i;
            }
        }
    }
    printf("! %d %d\n", a, b);
    fflush(stdout);
    return 0;
}

