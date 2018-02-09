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
const int maxn = 1e5+10;
struct Node
{
    int x, y, id;
    bool operator < (const Node &rbs)
    {
        if(x != rbs.x)return x < rbs.x;
        return y < rbs.y;
    }
}v[maxn];

int Abs(int x)
{
    return x<0?-x:x;
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        sc(v[i].x);sc(v[i].y);
        v[i].id = i;
    }
    sort(v, v + n);
    int ansi = v[0].id, ansj = v[1].id;
    ll dx = Abs(v[1].x-v[0].x), dy = Abs(v[1].y-v[0].y);
    for(int i = 2; i < n; i++){
        ll nx = Abs(v[i].x-v[0].x), ny = Abs(v[i].y-v[0].y);
        if(ny*dx>nx*dy){
            dx = nx;
            dy = ny;
            ansj = v[i].id;
        }
    }
    printf("%d %d\n", ansi+1, ansj+1);
    return 0;
}

