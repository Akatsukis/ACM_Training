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
const int maxn = 1e5 + 10;
int n, kase;
struct node
{
    int pos[maxn];
    int ch;
    bool operator < (const node &b)const
    {
        for(int i = maxn - 1; i >= 0; i--){
            if(pos[i] != b.pos[i])return pos[i] < b.pos[i];
        }
        return 0;
    }
}a[26];
char s[maxn];
bool ban[26];
bool vis[26];

void work()
{
    memset(ban, 0, sizeof(ban));
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < 26; i++){
        a[i].ch = i;
    }
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        int len = strlen(s);
        if(len>1)ban[s[0]-'a'] = 1;
        for(int j = len - 1; j >= 0; j--){
            a[s[j]-'a'].pos[len-1-j]++;
            vis[s[j]-'a'] = 1;
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < maxn; j++){
            while(a[i].pos[j] >= 26){
                a[i].pos[j] -= 26;
                a[i].pos[j+1]++;
            }
        }
    }
    sort(a, a + 26);
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(vis[i])cnt++;
    }
    if(cnt == 26){
        for(int i = 0; i < 26; i++){
            if(!ban[a[i].ch]){
                swap(a[i], a[25]);
            }
        }
    }
    for(int i = 25; i >= 26-cnt; i--){
        ll tmp = 1;
        for(int j = 0; j < maxn; j++){
            ans += tmp * a[i].pos[j] * i;
            ans %= mod;
            tmp *= 26;
            tmp %= mod;
        }
    }
    printf("Case #%d: %lld\n", kase++, ans);
}

int main()
{
    //freopen("1002.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    kase = 1;
    while(scanf("%d", &n) != EOF){
        work();
    }
    return 0;
}


