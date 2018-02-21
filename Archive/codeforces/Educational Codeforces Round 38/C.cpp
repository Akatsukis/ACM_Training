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
    int T;
    sc(T);
    while(T--){
        int x;
        sc(x);
        bool flag = 0;
        if(x==0){
            printf("1 1\n");
            continue;
        }
        for(int i = 1; i < sqrt(x); i++){
            if(x%i==0){
                int p = i, q = x/i;
                if((p+q)%2==0){
                    int a = (q+p)/2;
                    int b = (q-p)/2;
                    if(b <= a/2){
                        int n = a;
                        int m = a/(b+1)+1;
                        if(n*n-(n/m)*(n/m)==x){
                            flag = 1;
                            printf("%d %d\n", n, m);
                            break;
                        }   
                    }
                }
            }
        }
        if(!flag)printf("-1\n");
    }
    return 0;
}
