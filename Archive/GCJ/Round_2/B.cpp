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
    int T, kase = 1;
    sc(T);
    while(T--){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)swap(a, b);
        int ret = 0, now = 1;
        bool update = 1;
        while(update){
            update = 0;
            for(int i = now/2; i >= 0; i--){
                int u = i, v = now-i;
                if(a >= u && b >= v){
                    update = 1;
                    //printf("u=%d, v=%d\n", u, v);
                    ret++;
                    a -= u, b -= v;
                }
                if(a >= v && b >= u && u != v){
                    update = 1;
                    //printf("u=%d, v=%d\n", v, u);
                    ret++;
                    a -= v, b -= u;
                }
            }
            now++;
        }
        printf("Case #%d: %d\n", kase++, ret);
    }
    return 0;
}

