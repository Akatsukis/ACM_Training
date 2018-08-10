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
const int maxn = 1e3+10;
struct atom
{
    int sum, id;
    bool operator < (const atom &rhs)
    {
        if(sum != rhs.sum)return sum > rhs.sum;
        return id < rhs.id;
    }
}tb[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            int x; sc(x);
            tb[i].sum += x;
        }
        tb[i].id = i;
    }
    sort(tb+1, tb+1+n);
    for(int i = 1; i <= n; i++){
        if(tb[i].id == 1){
            printf("%d\n", i);
            break;
        }   
    }
    return 0;
}


