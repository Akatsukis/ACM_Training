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
const int maxn = 3e5+10;
struct atom
{
    int l, r, id;
    bool operator < (const atom &rhs)const
    {
        if(l != rhs.l)return l < rhs.l;
        return r > rhs.r;
    }
}p[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(p[i].l); sc(p[i].r);
        p[i].id = i;
    }
    sort(p+1, p+1+n);
    for(int l = 1, r = 2; l <= n && r <= n; ){
        if(p[r].r <= p[l].r){
            printf("%d %d\n", p[r].id, p[l].id);
            return 0;
        }
        else{
            l++;
        }
        if(l == r)r++;
    }
    printf("-1 -1\n");
    return 0;
}

