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
const int maxn = 100;
vector<int> v[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n, m;
        sc(n);sc(m);
        bool flag = 1;
        for(int i = 0; i <= n; i++)v[i].clear();
        for(int i = 0; i < m; i++){
            int mon, day, x, y;
            scanf("%d-%d %d %d", &mon, &day, &x, &y);
            for(int j = 1; j < mon ; j++){
                if(j == 2)day += 28;
                else if(j == 4 || j == 6 || j == 9 || j == 11)day += 30;
                else day += 31;
            }
            for(int j = 0; j < (int)v[x].size(); j++){
                if(abs<int>(v[x][j] - day) < 2)flag = 0;
            }
            for(int j = 0; j < (int)v[y].size(); j++){
                if(abs<int>(v[y][j] - day) < 2)flag = 0;
            }
            v[x].pb(day);
            v[y].pb(day);
        }
        if(flag)printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}

