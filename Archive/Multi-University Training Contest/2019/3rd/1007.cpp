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
const int maxn = 2e5+10;
int a[maxn], cnt[maxn*4];
ll sum[maxn*4];
vector<int> vec;

void update(int a, int k, int l, int r, int val)
{
    if(l == r-1) {
        cnt[k]++;
        sum[k] += val;
        return;
    }
    int m = (l+r)/2;
    if(a < m)update(a, k*2+1, l, m, val);
    else update(a, k*2+2, m, r, val);
    cnt[k] = cnt[k*2+1]+cnt[k*2+2];
    sum[k] = sum[k*2+1]+sum[k*2+2];
}

int query(int k, int l, int r, ll val) 
{
    if(val <= 0)return 0;
    if(l == r-1) {
        int ans = min(1LL*cnt[k], (val+vec[l]-1)/vec[l]);
        return ans;
    }
    int m = (l+r)/2;
    if(sum[k*2+2] >= val) {
        int ans = query(k*2+2, m, r, val);
        return ans;
    }
    else{
        int ans = cnt[k*2+2]+query(k*2+1, l, m, val-sum[k*2+2]);
        return ans;
    }

}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        vec.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            vec.push_back(a[i]);
        }
        sort(ALL(vec));
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int tot = vec.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            int ans = 0;
            int id = lower_bound(ALL(vec), a[i])-vec.begin();
            if(sum <= m)ans = 0;
            else ans = query(0, 0, tot, sum-m);
            update(id, 0, 0, tot, a[i]);
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}

