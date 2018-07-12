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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int qpow(ll a, int n)
{
    ll ret = 1;
    while(n){
        if(n%2)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    //int n = 10;
    //for(int i = 2; i <= n; i++){
        //int p = 0, q = 0;
        //vector<int> vec;
        //for(int j = 1; j <= i; j++)vec.pb(j);
        //do{
            //int Alice = 0, Bob = 0;
            //for(int k = 0; k < (int)vec.size(); k++){
                //if(vec[k] == 1)Alice = k+1;
                //if(vec[k] == 2)Bob = k+1;
            //}
            //for(int k = 0; k <= i; k++){
                //if(Alice > k && Bob <= k){
                    //p += Alice-k;
                    //q++;
                //}
            //}
        //}while(next_permutation(ALL(vec)));
        //int d = gcd(p, q);
        //p /= d, q /= d;
        //printf("n=%d, ans=%d/%d\n", i, p, q);
    //} 
    //puts("");
    //for(int i = 2; i <= n; i++){
        //int p = 0, q = 0;
        //vector<int> vec;
        //for(int j = 1; j <= i; j++)vec.pb(j);
        //do{
            //int Alice = 0, Bob = 0;
            //for(int k = 0; k < (int)vec.size(); k++){
                //if(vec[k] == 1)Alice = k+1;
                //if(vec[k] == 2)Bob = k+1;
            //}
            //for(int k = 0; k <= i; k++){
                //if(Alice > k && Bob > k){
                    //p += Alice-k;
                    //q++;
                //}
            //}
        //}while(next_permutation(ALL(vec)));
        //int d = gcd(p, q);
        //p /= d, q /= d;
        //printf("n=%d, ans=%d/%d\n", i, p, q);
    //} 
    int T;
    sc(T);
    while(T--){
        int n, d;
        scanf("%d%d", &n, &d);
        if(d == 1){
            int ans = 1LL*(n+2)*qpow(4, mod-2)%mod;
            printf("%d\n", ans);
        }
        else{
            int ans = 1LL*(3LL*n+6)*qpow(8, mod-2)%mod;
            printf("%d\n", ans);
        }
    }
    return 0;
}

