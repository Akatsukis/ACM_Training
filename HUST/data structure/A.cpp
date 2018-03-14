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
#define sqr(x) ((x)*(x))
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
const int maxn = 2e5+10;
char s[maxn];
bool del[maxn];
int tree[maxn];
set<int> st[70];
int n, m;

int trs(char c)
{
    if(isdigit(c))return c-'0';
    else if(isupper(c))return c-'A'+10;
    else return c-'a'+36;
}

void add(int x)
{
    while(x <= n){
        tree[x]++;
        x += x&(-x);
    }
}

int sum(int x)
{
    int ret = 0;
    while(x){
        ret += tree[x];
        x -= x&(-x);
    }
    return ret;
}

int upd(int x)
{
    int ret = n-1, l = 0, r = n-1;
    while(l <= r){
        int m = (l+r)/2;
        if(m-sum(m+1) >= x-1){
            ret = m;
            r = m-1;
        }
        else l = m+1;
    }
    return ret;
}

int main()
{
    sc(n); sc(m);
    scanf("%s", s);
    for(int i = 0; i < n; i++){
        st[trs(s[i])].insert(i);
    }
    for(int i = 0; i < m; i++){
        int l, r, id;
        char c;
        scanf("%d %d %c", &l, &r, &c);
        l = upd(l); r = upd(r), id = trs(c);
        set<int>::iterator itl, itr;
        itl = lower_bound(st[id].begin(), st[id].end(), l);
        itr = upper_bound(st[id].begin(), st[id].end(), r);
        while(itl != itr){
            add((*itl)+1);
            del[*itl] = 1;
            st[id].erase(itl++);
        }
    }
    for(int i = 0; i < n; i++){
        if(!del[i])putchar(s[i]);
    }
    puts("");
    return 0;
}

