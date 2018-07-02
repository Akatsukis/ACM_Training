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
const int maxn = 1e5+10;
int a[maxn], sum1[maxn], sum2[maxn];


int main()
{
    int n, b;
    sc(n); sc(b);
    for(int i = 0; i < n; i++){
        sc(a[i]);
        sum1[i] = sum1[i-1];
        sum2[i] = sum2[i-1];
        if(a[i]&1)sum1[i]++;
        else sum2[i]++;
    }
    vector<int> ans;
    for(int i = 0; i < n-1; i++){
        if(sum1[i] == sum2[i])ans.pb(Abs(a[i]-a[i+1]));
    }
    sort(ALL(ans));
    int ret = 0;
    for(auto u : ans){
        b -= u;
        if(b < 0)break;
        else ret++;
    }
    printf("%d\n", ret);
    return 0;
}

