#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxm = 110;
const int maxn = 1e7 + 10;
unsigned a, b, c, x, y, z;
int n, m;
struct node
{
    int id, k;
    bool operator < (const node& b)const{
        return k > b.k;
    }
}p[maxm];
unsigned ans[maxm];
unsigned A[maxn];
int kase;

unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}


void work()
{
    x = a, y = b, z = c;
    for(int i = 0; i < m ; i++){
        sc(p[i].k);
        p[i].id = i;
    }
    for(int i = 0; i < n; i++){
        A[i] = rng61();
    }
    p[m].k = n;
    p[m].id = m;
    sort(p, p + m + 1);
    for(int i = 1; i <= m; i++){
        nth_element(A, A + p[i].k, A + p[i - 1].k);
        //printf("p[%d].k=%d, p[%d].id=%d p[%d-1].id=%d\n", i, p[i].k, i, p[i].id, i, p[i-1].k);
        ans[p[i].id] = A[p[i].k];
    }
    printf("Case #%d: ", kase++);
    for(int i = 0; i < m; i++){
        printf("%u%c", ans[i], i == m - 1 ? '\n' : ' ');
    }
}


int main()
{
    kase = 1;
    while(scanf("%d%d%u%u%u", &n, &m, &a, &b, &c) != EOF){
        work();
    }
    return 0;
}


