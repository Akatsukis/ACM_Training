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

int main()
{
    int v1, v2, v3, vm;
    scanf("%d%d%d%d", &v1, &v2, &v3, &vm);
    for(int i = 1; i <= 300; i++){
        for(int j = i+1; j <= 300; j++){
            for(int  k= j+1; k <= 300; k++){
                if(v1 <= k && v1*2 >=k && v2 <= j && v2*2 >= j &&v3 <= i && v3*2 >= i && vm <= i && vm*2 >= i && vm*2 < j){
                    printf("%d\n%d\n%d\n", k, j, i);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}

