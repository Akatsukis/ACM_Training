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
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1000;
ll q[maxn];
ll a[maxn];

int main()
{
    ll ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < (int)s.size(); i++){
        if(i)q[i] = q[i-1];
        if(i)a[i] = a[i-1];
        if(s[i] == 'Q')q[i]++;
        if(s[i] == 'A')a[i]++;
    }
    for(int i = 0; i <(int)s.size(); i++){
        if(s[i]=='A')ans += (q[n-1]-q[i])*q[i];
    }
    printf("%lld\n", ans);
    return 0;
}

