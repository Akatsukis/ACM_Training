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
const int maxn = 1000+10;
char s[maxn][10];
ll sum[10];
ll Pow[10];
pii p[10];
bool vis[10];

void init()
{
    Pow[0] = 1;
    for(int i = 1; i < 7; i++){
        Pow[i] = Pow[i-1] * 10;
    }
}

bool cmp(pii a, pii b)
{
    return a.fi > b.fi;
}

int main()
{
    init();
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        vis[s[i][0]-'a'] = 1;
        int len = strlen(s[i]);
        for(int j = len-1; j >= 0; j--){
            int id = s[i][j] - 'a';
            sum[id] += Pow[len-j-1];
        }
    }
    for(int i = 0; i < 10; i++){
        p[i].fi = sum[i], p[i].se = i;
        //printf("p[%d]={%d,%d}\n", i, p[i].fi, p[i].se);
    }
    sort(p, p + 10, cmp);
//    for(int i = 0; i < 10; i++){
//        printf("p[%d]={%d,%d}\n", i, p[i].fi, p[i].se);
//    }
    ll ans = 0;
    if(vis[p[0].se]){
        for(int i = 1; i <= 9; i++){
            if(!vis[p[i].se]){
                for(int j = i; j > 0; j--){
                    swap(p[j], p[j-1]);
                }
                break;
            }
        }
    }
//    for(int i = 0; i < 10; i++){
//        printf("p[%d]={%d,%d}\n", i, p[i].fi, p[i].se);
//    }
    for(int i = 0; i < 10; i++){
        ans += (ll)i*p[i].fi;
    }
    printf("%lld\n", ans);
    return 0;
}

