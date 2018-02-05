#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3000+10;
bool ocp[maxn][maxn];

int main()
{
    int n, m, k;
    sc(n);sc(m);sc(k);
    for(int i = 0; i < n; i++){
        char s[maxn];
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == '*')ocp[i][j] = 1;
            else ocp[i][j] = 0;
        }
    }
    if(k == 1){
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!ocp[i][j])ans++;
            }
        }
        printf("%d\n", ans);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(ocp[i][j]){
                if(cnt >= k)ans += cnt-k+1;
                cnt = 0;
            }
            else cnt++;
        }
        if(cnt >= k)ans += cnt-k+1;
    }
	for(int i = 0; i < m; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(ocp[j][i]){
                if(cnt >= k)ans += cnt-k+1;
                cnt = 0;
            }
            else cnt++;
        }
        if(cnt >= k)ans += cnt-k+1;
    }
    printf("%d\n", ans);
    return 0;
}

