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
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int ans = 0, mx = -INF;
    for(int i = 1; i <= k; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        if(mx <= u*m+(n-m)*v){
            mx = u*m+(n-m)*v;
            ans = i;
        }
    }
    for(int i = 1; i <= k; i++){
        if(ans == i)printf("%d%c", n, " \n"[i==k]);
        else printf("0%c", " \n"[i==k]);
    }
    return 0;
}

