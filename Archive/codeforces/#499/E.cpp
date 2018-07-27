#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e5+10;
bool vis[maxn];
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vec;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        vec.pb(x%k);
    }
    vector<int> ans;
    ans.pb(0);
    int now = k;
    for(auto u : vec)now = gcd(now, u);
    for(int i = now; i < k; i += now)ans.pb(i);
    int sz = ans.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; i++)printf("%d%c", ans[i], " \n"[i==sz-1]);
}
