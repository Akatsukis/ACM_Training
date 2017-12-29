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
int a[maxn];
set<int> st[200];
int n;

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        st[a[i]].insert(i);
    }
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int l, r, x, y;
        sc(l);sc(r);sc(x);sc(y);
        set<int>::iterator itl = lower_bound(st[x].begin(), st[x].end(), l);
        set<int>::iterator itr = upper_bound(st[x].begin(), st[x].end(), r);
        set_union(st[y].begin(), st[y].end(), itl, itr, inserter(st[y], st[y].begin()));
        st[x].erase(itl, itr);
    }
    for(int i = 1; i <= 100; i++){
        for(auto it = st[i].begin(); it != st[i].end(); it++){
            a[*it] = i;
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d%c", a[i], " \n"[i==n]);
    }
    return 0;
}

