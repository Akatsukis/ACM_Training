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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int n;
int par[maxn];
char s1[maxn];
char s2[maxn];
char ans[maxn][2];
int cnt;

int find(int x)
{
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y)par[x] = y;
}

int main()
{
    scanf("%d%s%s", &n, s1, s2);
    for(int i = 1; i <= 26; i++)par[i] = i;
    for(int i = 0; i < n; i++){
        if(find(s1[i]-'a') != find(s2[i]-'a')){
            ans[cnt][0] = s1[i], ans[cnt][1] = s2[i];
            cnt++;
            unite(s1[i]-'a', s2[i]-'a');
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%c %c\n", ans[i][0], ans[i][1]);
    }
    return 0;
}

