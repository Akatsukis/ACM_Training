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
const int maxn = 1e6+10;
const int maxm = 1e4+10;
int a[maxn], b[maxm], nxt[maxn];
int n, m;

void get_next()
{
    int k = -1;
    nxt[0] = -1;
    for(int i = 1; i < m; i++){
        while(k >= 0 && b[i] != b[k+1])k = nxt[k];
        if(b[i] == b[k+1])k++;
        nxt[i] = k;
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n); sc(m);
        for(int i = 0; i < n; i++)sc(a[i]);
        for(int i = 0; i < m; i++)sc(b[i]);
        get_next();
        int ans = -1, k = -1;
        for(int i = 0; i < n; i++){
            while(k >= 0 && a[i] != b[k+1])k = nxt[k];
            if(a[i] == b[k+1])k++;
            if(k == m-1){
                ans = i-m+2;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

