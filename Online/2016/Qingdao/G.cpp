#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x);
const int maxn = 1e5+10;
int a[maxn];
int n, k;

bool ok(int val, int m)
{
    int ret = 0;
    queue<int> q1, q2;
    for(int i = 0; i < m-1-(n-1)%(m-1); i++)q1.push(0);
    for(int i = 0; i < n; i++)q1.push(a[i]);
    while((int)q1.size()+(int)q2.size() > m){
        int sum = 0;
        for(int i = 0; i < m; i++){
            if(q1.empty()){
                sum += q2.front(); q2.pop();
            }
            else if(q2.empty()){
                sum += q1.front(); q1.pop();
            }
            else if(q1.front() < q2.front()){
                sum += q1.front(); q1.pop();
            }
            else{
                sum += q2.front(); q2.pop();
            }
        }
        ret += sum;
        if(ret > val)return 0;
        q2.push(sum);
    }
    return 1;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            sc(a[i]); k -= a[i];
        }
        sort(a, a+n);
        int l = 2, r = n, ans = n;
        while(l <= r){
            int m = (l+r)>>1;
            if(ok(k, m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
