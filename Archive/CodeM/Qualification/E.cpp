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
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
struct Time
{
    int hh, mm;
    bool operator > (const Time &rhs)const
    {
        if(hh != rhs.hh)return hh > rhs.hh;
        else return mm > rhs.mm;
    }
    bool operator < (const Time &rhs)const
    {
        if(hh != rhs.hh)return hh < rhs.hh;
        else return mm < rhs.mm;
    }
    bool operator <= (const Time &rhs)const
    {
        if(hh != rhs.hh)return hh <= rhs.hh;
        else return mm <= rhs.mm;
    }
    Time operator + (const int &rhs)const
    {
        Time ret = *this;
        ret.mm += rhs;
        ret.hh += ret.mm/60;
        ret.mm = ret.mm%60;
        return ret;
    }
}lst[maxn];
struct edge
{
    int to, cost;
    Time t1, t2;
};
vector<edge> G[maxn];
vector<edge> G2[maxn];

void dijkstra_time(int s)
{
    priority_queue<pair<Time, int> > pq;
    memset(lst, 0, sizeof(lst));
    lst[s] = Time{0, 0};
    pq.push(mk(lst[s], s));
    while(!pq.empty()){
        Time now = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if(lst[u] > now)continue;
        for(auto e : G[u]){
            if(e.t1 >= lst[u] && lst[e.to] < lst[u]+30){
                lst[e.to] = e.t1;
                pq.push(mk(lst[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, w, fhh, fmm, thh, tmm;
        scanf("%d%d%d%d:%d%d:%d", &u, &v, &w, &fhh, &fmm, &thh, &tmm);
        Time t1, t2;
        t1.hh = fhh, t1.mm = fmm, t2.hh = thh, t2.mm = tmm;
        G[u].pb(edge{v, w, t1, t2+30});
        G2[v].pb(edge{u, 0, t1, t2+30});
    }
    dijkstra_time(1);
    return 0;
}

