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
#define Abs(x) ((x)>=0?(x):(-(x)))
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int a[maxn];

int main()
{
    int n, d; 
    sc(n); sc(d);
    for(int i = 0; i < n; i++){
        sc(a[i]);
    }
    set<int> st;
    for(int i = 0; i < n; i++){
        int now = a[i]-d;
        bool flg = 1;
        for(int j = 0; j < n; j++){
            if(Abs(a[j]-now) < d){
                flg = 0;
                break;
            }
        }
        if(flg)st.insert(now);
        now = a[i]+d;
        flg = 1;
        for(int j = 0; j < n; j++){
            if(Abs(a[j]-now) < d){
                flg = 0;
                break;
            }
        }
        if(flg)st.insert(now);
    }
    printf("%d\n", (int)st.size());
    return 0;
}

