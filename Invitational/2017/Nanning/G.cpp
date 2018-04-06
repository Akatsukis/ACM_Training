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
const int maxn = 1e6+10;
int a[maxn];
int num[maxn];

int main()
{
    int n;
    while(sc(n) != EOF){
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++)sc(a[i]), num[a[i]]++;
        int ret = 0;
        for(int i = 1; i <= n; i++){
             int tmp = (num[i]-1)/2*2;
             num[i] -= tmp;
             ret += tmp/2;
        }
        for(int i = 3; i <= n; i++){
            if(num[i-2] >= 2){
                num[i-2] -= 2;
                ret++;
            }
            if(num[i-2] >= 1 && num[i-1] >= 2 && num[i] >= 1){
                num[i-1] -= 2;
                ret++;
            }
            if(num[i-2] >= 1 && num[i-1] >= 1 && num[i] >= 1){
                num[i-2] -= 1, num[i-1] -= 1, num[i] -= 1;
                ret++;
            }
        }
        for(int i = 1; i <= n; i++)if(num[i] >= 2)num[i] -= 2, ret++;
        printf("%d\n", ret);
    }
    return 0;
}

