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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int ans[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        sc(n);
        int cnt = 1;
        for(int i = 1; i <= n; i += 2){
            ans[i] = cnt++;
        }
        for(int i = 2; i <= n; i += 2){
            ans[i] = cnt++;
        }
        for(int i = 1; i <= n; i++)printf("%d%c", ans[i], " \n"[i==n]);
    }
    return 0;
}

