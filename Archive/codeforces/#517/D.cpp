#include <bits/stdc++.h>
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
const int maxn = 2e3+10;
char mp[maxn][maxn];
int n, k;

void bfs()
{
    queue<pair<pii, int> > q;
    q.push(mk(mk(0, 0), 0));
    while(!q.empty()){
    }
}

int main()
{
    sc(n); sc(k);
    for(int i = 0; i < n; i++)scanf("%s", mp[i]);
    bfs();
    return 0;
}

