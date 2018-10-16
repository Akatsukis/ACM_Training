#include <cstdio>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 2e2+10;
bool vis[maxn];
vector<int> prime;
set<int> st, ans;

void init()
{
    for(int i = 2; i < maxn; i++){
        if(!vis[i])prime.pb(i);
        for(int j = 0; j < SZ(prime) && i*prime[j] < maxn; j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)break;
        }
    }
    for(int i = 0; i < SZ(prime); i++){
        for(int j = i+1; j < SZ(prime); j++){
            if(prime[i]*prime[j] < maxn)st.insert(prime[i]*prime[j]);
        }
    }
    for(auto u : st){
        for(auto v : st){
            if(u+v < maxn)ans.insert(u+v);
        }
    }
}

int main()
{
    init();
    int T; sc(T);
    while(T--){
        int n; sc(n);
        if(ans.count(n))puts("YES");
        else puts("NO");
    }
    return 0;
}

