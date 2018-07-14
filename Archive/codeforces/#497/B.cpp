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
    bool flg = 1;
    int now = INF;
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int u, v;
        sc(u); sc(v);
        if(now < u && now < v){
            flg = 0;
            break;
        }
        else{
            if(now >= max(u, v))now = max(u, v);
            else now = min(u, v);
        }
    }
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}

