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
const int maxn = 2e5+10;
int a[maxn], b[maxn], ma[maxn];
int n;

int manacher()
{
    b[0] = -2, b[1] = -1;
    for(int i = 0; i < n; i++){
        b[i*2+2] = a[i];
        b[i*2+3] = -1;
    }
    int mx = -1, ctr = -1, ret = 1;
    for(int i = 1; i < 2*n+2; i++){
        if(mx > i)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(b[i-ma[i]] == -1 || (b[i-ma[i]] == b[i+ma[i]] && b[i-ma[i]] <= b[i-ma[i]+2]))ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
        ret = max(ret, ma[i]-1);
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        int ans = manacher();
        printf("%d\n", ans);
    }
    return 0;
}

