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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e4 + 10;
int n, cur;
int s[maxn];
bool flag;
int p, q;

struct Trie
{
    int nxt[2];
    vector<int> v;
};

Trie trie[maxn*31*2];

void build(int &node, int val, int bit, int id)
{
    //printf("%d %d %d %d %d\n", node, val, bit, id, cur);
    if(!node)node = ++cur;
    //printf("%d %d\n", trie[node].nxt[0], trie[node].nxt[1]);
    if(bit == -1){
        trie[node].v.pb(id);
        return;
    }
    bool t = (val >> bit) & 1;
    build(trie[node].nxt[t], val, bit - 1, id);
}


int query(int node, int val, int bit)
{
    //printf("%d %d %d\n", node, val, bit);
    if(bit == -1){
        for(int i = 0; i < (int)trie[node].v.size(); i++){
            if(trie[node].v[i] != p && trie[node].v[i] != q){
                flag = 1;
            }
        }
        return 0;
    }
    bool t = (val >> bit) & 1;
    int res = 0;
    if(trie[node].nxt[!t]){
        int now = query(trie[node].nxt[!t], val, bit - 1);
        if(flag)return max(res, now + (1<<bit));
    }
    if(trie[node].nxt[t]){
        int now = query(trie[node].nxt[t], val, bit - 1);
        if(flag)return max(res, now);
    }
    //printf("bit=%d, res=%d\n", bit, res);
    return res;
}



int main()
{
    int T;
    sc(T);
    while(T--){
        for(int i = 0; i <= cur; i++){
            trie[i].nxt[0] = trie[i].nxt[1] = 0;
            trie[i].v.clear();
        }
        cur = 1;
        sc(n);
        for(int i = 1; i <= n; i++){
            sc(s[i]);
        }
        int rt = 1;
        for(int i = 1; i <= n; i++){
            build(rt, s[i], 30, i);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                int now = s[i] + s[j];
                flag = 0, p = i, q = j;
                ans = max(ans, query(1, now, 30));
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}


