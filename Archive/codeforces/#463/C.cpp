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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int n, a, b;
    sc(n);sc(a);sc(b);
    bool flag = 0;
    for(int i = 0; i*a <= n; i++){
        if((n-i*a)%b==0){
            flag = 1;
            int p = i, q = (n-i*a)/b;
            int now = 1;
            for(int j = 0; j < p; j++){
                for(int k = 1; k < a; k++)printf("%d ", now+k);
                printf("%d ", now);
                now += a;
            }
            for(int j = 0; j < q; j++){
                for(int k = 1; k < b; k++)printf("%d ", now+k);
                printf("%d ", now);
                now += b;
            }
            printf("\n");
            break;
        }
    }
    if(!flag)printf("-1\n");
    return 0;
}

