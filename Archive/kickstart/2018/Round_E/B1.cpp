#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, string> psi;
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
const int INF = 0x3f3f3f3f;
const int maxn = 110;
int num[maxn];
char s[maxn];
set<string> ban;
map<string, int> dist;
int n, m, p;

int solve(string t, int val)
{
    priority_queue<psi, vector<psi>, greater<psi> > pq;
    dist[t] = val;
    pq.push(mk(dist[t], t));
    while(!pq.empty()){
        psi u = pq.top(); pq.pop();
        if(dist[u.se] < u.fi)continue;
        if(!ban.count(u.se))return u.fi;
        for(int i = 0; i < p; i++){
            string v = u.se;
            int now = u.fi;
            if(v[i] == '1'){
                v[i] = '0';
                now = now-(n-num[i])+num[i];
            }
            else{
                v[i] = '1';
                now = now-num[i]+(n-num[i]);
            }
            if(!dist.count(v) || dist[v] > now){
                dist[v] = now;
                pq.push(mk(dist[v], v));
            }
        }
    }
    return 0;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(num, 0, sizeof(num));
        dist.clear();
        ban.clear();
        sc(n); sc(m); sc(p);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < p; j++){
                if(s[j] == '1')num[j]++;
            }
        }
        for(int i = 0; i < m; i++){
            string s;
            cin >> s;
            ban.insert(s);
        }
        string t;
        int now = 0;
        for(int i = 0; i < p; i++){
            if(num[i] >= n-num[i])t += "1", now += n-num[i];
            else t += "0", now += num[i];
        }
        int ans = solve(t, now);
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}


