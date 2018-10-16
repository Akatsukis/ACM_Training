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
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e4;
int t[maxn+10];
ull tb[maxn+10];

int main()
{
    ull buc = (-1ull)/maxn;
    ull a, b, l, n, fst;
    scanf("%llu%llu%llu%llu%llu", &a, &b, &l, &n, &fst);
    ull cur = fst;
    for(ull i = 0; i < n; i++){
        t[cur/buc]++;
        cur = cur*a+b;
    }
    int now = 0;
    for(int i = 0; i < maxn; i++){
        if(l > (ull)t[i])l -= t[i];
        else{
            now = i;
            break;
        }
    }
    cur = fst;
    int cnt = 0;
    for(ull i = 0; i < n; i++){
        if(cur/buc == (ull)now){
            tb[cnt++] = cur;
        }
        cur = cur*a+b;
    }
    l--;
    nth_element(tb, tb+l, tb+cnt);
    printf("%llu\n", tb[l]);
    return 0;
}

