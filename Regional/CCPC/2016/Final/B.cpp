#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn = 1e6+10;
struct Node
{
    ll time;
    int val;
    Node(){}
    Node(ll time, int val):time(time), val(val){}
    bool operator < (const Node &rhs)const
    {
        return time > rhs.time;
    }
};
ll t[maxn];
int L, n, m;

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &L, &n, &m);
        priority_queue<Node> pq;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            pq.push(Node(x, x));
        }
        for(int i = 0; i < L; i++){
            Node u = pq.top(); pq.pop();
            t[i] = u.time;
            pq.push(Node(u.time+u.val, u.val));
        }
        while(!pq.empty())pq.pop();
        for(int i = 0; i < m; i++){
            int x;
            scanf("%d", &x);
            pq.push(Node(x, x));
        }
        ll ans = 0;
        for(int i = L-1; i >= 0; i--){
            Node u = pq.top(); pq.pop();
            ans = max(ans, t[i]+u.time);
            pq.push(Node(u.time+u.val, u.val));
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}
