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
const int maxn = 2e5+10;
set<int> st[70];
int tree[maxn];
bool vis[maxn];
char s[maxn];
int n, m;

int sum(int x)
{
    int res = 0;
    while(x){
        res += tree[x];
        x -= x&(-x);
    }
    return res;
}

void add(int x)
{
    while(x <= n){
        tree[x] += -1;
        x += x&(-x);
    }
}

int lwd(int x)
{
    int l = 0, r = n-1, res = n-1;
    while(l <= r){
        int m = (l+r)/2;
        if(m+sum(m+1) >= x){
            res = m;
            r = m-1;
        }
        else l = m+1;
    }
    return res;
}

int main()
{
    sc(n);sc(m);
    scanf("%s", s);
    for(int i = 0; i < n; i++){
        if(islower(s[i])){
            st[s[i]-'a'].insert(i);
        }
        else if(isupper(s[i])){
            st[s[i]-'A'+26].insert(i);
        }
        else if(isdigit(s[i])){
            st[s[i]-'0'+52].insert(i);
        }
    }
    for(int i = 0; i < m; i++){
        int l, r, id;
        char c;
        scanf("%d %d %c", &l, &r, &c);
        l--;r--;
        l = lwd(l);
        r = lwd(r);
        //pr(l);pr(r);
        set<int>::iterator itl, itr;
        if(islower(c))id = c-'a';
        else if(isupper(c))id = c-'A'+26;
        else if(isdigit(c))id = c-'0'+52;
        itl = lower_bound(st[id].begin(), st[id].end(), l);
        itr = upper_bound(st[id].begin(), st[id].end(), r);
        while(itl != itr){
            //printf("*itl=%d\n", *itl);
            if(!vis[*itl]){
                add((*itl)+1);
            }
            vis[*itl] = 1;
            st[id].erase(itl++);
        }
    }
    for(int i = 0; i < n; i++){
        if(!vis[i])printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

