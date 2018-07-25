#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ALL(x) x.begin(), x.end()
const int maxn = 1e5+10;
int a[maxn], bit[maxn];
int n, sz;
vector<int> vec;

void init()
{
    vec.clear();
    memset(bit, 0, sizeof(int)*(n+1));
}

int sum(int x)
{
    int ret = 0;
    while(x){
        ret += bit[x];
        x -= x&-x;
    }
    return ret;
}

void add(int x)
{
    while(x <= sz){
        bit[x]++;
        x += x&-x;
    }
}

int main()
{
    int x, y;
    while(scanf("%d%d%d", &n, &x, &y) != EOF){
        init();
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            vec.pb(a[i]);
        }
        sort(ALL(vec));
        vec.erase(unique(ALL(vec)), vec.end());
        ll ans = 0;
        sz = vec.size();
        for(int i = 0; i < n; i++){
            int id = lower_bound(ALL(vec), a[i])-vec.begin()+1;
            ans += sum(sz)-sum(id);
            add(id);
        }
        printf("%lld\n", ans*min(x, y));
    }
}
