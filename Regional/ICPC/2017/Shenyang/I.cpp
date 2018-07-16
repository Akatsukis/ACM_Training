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

int main()
{
    int T;
    sc(T);
    while(T--){
        ull in[4], ans = 0;
        bool flg = 1;
        for(int i = 0; i < 4; i++){
            scanf("%llu", &in[i]);
            ans += in[i];
            if(in[i] != (1ull<<62))flg = 0;
        }
        if(flg)puts("18446744073709551616");
        else printf("%llu\n", ans);
    }
    return 0;
}

