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
    int u, v, id;
    bool operator < (const atom &rhs)const
    {
        if(u != rhs.u)return u > rhs.u;
        else return v > rhs.v;
    }
}p[maxn];

int main()
{
    int n, x1, x2;
    sc(n); sc(x1); sc(x2);
    for(int i = 0; i < n; i++){
        int w; sc(w);
        p[i].u = (x1-1+w)/w;
        p[i].v = (x2-1+w)/w;
        p[i].id = i+1;
    }
    sort(p, p+n);
    //for(int i = 0; i < n; i++){
        //printf("%d %d\n", p[i].u, p[i].v);
    //}
    for(int i = 0; i < n; i++){
        if(p[i].u < n-i && i+p[i].u <= n-p[i+p[i].u].v){
            //printf("p[%d].u=%d, p[%d].v=%d\n", i, p[i].u, i+p[i].u, p[i+p[i].u].v);
            printf("Yes\n");
            printf("%d %d\n", p[i].u, p[i+p[i].u].v);
            int from, sz;
            from = i, sz = p[i].u;
            for(int j = 0; j < sz; j++){
                printf("%d%c", p[from+j].id, " \n"[j==p[i].u-1]);
            }
            from = i+p[i].u, sz = p[i+p[i].u].v;
            for(int j = 0; j < sz; j++){
                printf("%d%c", p[from+j].id, " \n"[j==p[i+p[i].u].v-1]);
            }
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(p[i].v < n-i && i+p[i].v <= n-p[i+p[i].v].u){
            //printf("p[%d].u=%d, p[%d].v=%d\n", i, p[i].u, i+p[i].u, p[i+p[i].u].v);
            printf("Yes\n");
            printf("%d %d\n", p[i+p[i].v].u, p[i].v);
            int from, sz;
            from = i+p[i].v, sz = p[i+p[i].v].u;
            for(int j = 0; j < sz; j++){
                printf("%d%c", p[from+j].id, " \n"[j==sz-1]);
            }
            from = i, sz = p[i].v;
            for(int j = 0; j < sz; j++){
                printf("%d%c", p[from+j].id, " \n"[j==sz-1]);
            }
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

