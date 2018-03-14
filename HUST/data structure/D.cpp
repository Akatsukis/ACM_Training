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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int tree[6][12][12][maxn]; //tree[let][len][mod][BIT];
char s[maxn], t[12];
int n;

int trs(char c)
{
    string r = "ATCG";
    for(int i = 0; i < 4; i++)if(r[i]==c)return i;
    return 0;
}

void add(int x, int val)
{
    for(int i = 1; i <= 10; i++){
        for(int j = x+1; j <= n; j += j&(-j)){
            tree[trs(s[x])][i][x%i][j] += val;
        }
    }
}

int sum(int *arr, int l, int r)
{
    int ret = 0;
    while(r){
        ret += arr[r];
        r -= r&(-r);
    }
    while(l){
        ret -= arr[l];
        l -= l&(-l);
    }
    return ret;
}

int main()
{
    int q, k, x, l, r;
    scanf("%s%d", s, &q);
    n = strlen(s);
    for(int i = 0; i < n; i++)add(i, 1);
    for(int i = 0; i < q; i++){
        sc(k);
        if(k == 1){
            scanf("%d%s", &x, t);
            add(x-1, -1);
            s[x-1] = t[0];
            add(x-1, 1);
        }
        else{
            scanf("%d%d%s", &l, &r, t);
            l--;
            int m = strlen(t);
            int ret = 0;
            for(int j = 0; j < m; j++){
                ret += sum(tree[trs(t[j])][m][(l+j)%m], l, r);
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}

