#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
int a[maxn];
stack<int> sk;

int main()
{
    int n, k;
    sc(n);sc(k);
    for(int i = 1; i <= k; i++){
        sc(a[i]);
    }
    int nxt = 1, pos = 0;
    while(nxt != n+1 && pos+1 <= k){
        while(!sk.empty() && nxt == sk.top()){
            nxt++;
            sk.pop();
        }
        if(pos+1 <= k){
            if(!sk.empty() && a[pos+1] > sk.top()){
                printf("-1\n");
                return 0;
            }
            else sk.push(a[++pos]);
        }
    }
    int q = k+1;
    while(!sk.empty()){
        if(nxt == sk.top()){
            sk.pop();
            nxt++;
        }
        else{
            a[q++] = sk.top()-1;
            sk.push(sk.top()-1);
        }
    }
    int p = n;
    while(q <= n){
        a[q++] = p--;
    }
    for(int i = 1; i <= n; i++){
        printf("%d%c", a[i], " \n"[i==n]);
    }
    return 0;
}

