
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
#define Abs(x) ((x)>=0?(x):(-(x)))
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
int cl[maxn];
int ce[maxn];

int main()
{
    int n, m, p, q, v;
    scanf("%d%d%d%d%d", &n, &m, &p, &q, &v);
    for(int i = 0; i < p; i++)sc(cl[i]);
    for(int i = 0; i < q; i++)sc(ce[i]);
    int Q;
    sc(Q);
    for(int i = 0; i < Q; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 == x2){
            printf("%d\n", Abs(y1-y2));
            continue;
        }
        int ans = INF;
        int v1 = lower_bound(cl, cl+p, y1)-cl;
        if(v1 >= 0 && v1 < p){
            ans = min(ans, Abs(y1-cl[v1])+Abs(y2-cl[v1])+(Abs(x1-x2)));
        }
        v1--;
        if(v1 >= 0 && v1 < p){
            ans = min(ans, Abs(y1-cl[v1])+Abs(y2-cl[v1])+(Abs(x1-x2)));
        }
        v1 = lower_bound(ce, ce+q, y1)-ce;
        if(v1 >= 0 && v1 < q){
            ans = min(ans, Abs(y1-ce[v1])+Abs(y2-ce[v1])+(Abs(x1-x2)-1)/v+1);
        }
        v1--;
        if(v1 >= 0 && v1 < q){
            ans = min(ans, Abs(y1-ce[v1])+Abs(y2-ce[v1])+(Abs(x1-x2)-1)/v+1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
