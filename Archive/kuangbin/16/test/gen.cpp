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

int main()
{
    srand(unsigned(time(NULL)));
    int T = 5;
    for(int i = 0; i < T; i++){
        int n = 100;
        printf("%d\n", n);
        for(int i = 0; i < n; i++){
            int len = rand()%10+1;
            printf("%d ", len);
            for(int j = 0; j < len; j++)printf("%c", rand()%26+'a');
            puts("");
        }
    }
    return 0;
}

