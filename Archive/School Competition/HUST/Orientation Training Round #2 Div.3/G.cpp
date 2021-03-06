#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
map<string,int> cost;
string s1, s2, s;
int n;

int bfs()
{
    string now;
    for(int i = 0; i < n; i++){
        now.pb(s2[i]);
        now.pb(s1[i]);
    }
    cost[now] = 1;
    queue<string> q;
    q.push(now);
    while(q.size()){
        string tmp = q.front();q.pop();
        if(tmp == s)return cost[tmp];
        s1.clear();s2.clear();
        for(int i = 0; i < n; i++){
            s1.pb(tmp[i]);
            s2.pb(tmp[i+n]);
        }
        now.clear();
        for(int i = 0; i < n; i++){
            now.pb(s2[i]);
            now.pb(s1[i]);
        }
        if(!cost.count(now)){
            cost[now] = cost[tmp] + 1;
            q.push(now);
        }
    }
    return -1;
}


int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        cin >> s1 >> s2 >> s;
        int ans = bfs();
        printf("%d %d\n", kase++, ans);
    }
    return 0;
}


