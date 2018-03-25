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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 200100;
const int maxs = 128;
int buc[maxn], x[maxn], y[maxn], sa[maxn], rk[maxn], height[maxn];

void build_sa(string s)
{
    int len = s.size(), m = maxs;
    for(int i = 0; i < m; i++)buc[i] = 0;
    for(int i = 0; i < len; i++)buc[x[i]=s[i]]++;
    for(int i = 1; i < m; i++)buc[i] += buc[i-1];
    for(int i = len-1; i >= 0; i--)sa[--buc[x[i]]] = i;
    for(int k = 1; k <= len; k <<= 1){
        int p = 0;
        for(int i = len-1; i >= len-k; i--)y[p++] = i;
        for(int i = 0; i < len; i++)if(sa[i] >= k)y[p++] = sa[i]-k;
        for(int i = 0; i < m; i++)buc[i] = 0;
        for(int i = 0; i < len; i++)buc[x[y[i]]]++;
        for(int i = 1; i < m; i++)buc[i] += buc[i-1];
        for(int i = len-1; i >= 0; i--)sa[--buc[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for(int i = 1; i < len; i++){
            x[sa[i]] = (y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
        }
        if(p >= len)break;
        m = p;
    }
    for(int i = 0; i < len; i++)rk[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < len; i++){
        if(!rk[i])continue;
        if(k)k--;
        int j = sa[rk[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rk[i]] = k;
    }
}


int main()
{
    string s, t;
    cin >> s >> t;
    string r = s+"$"+t;
    build_sa(r);
    int ans = 0, n = r.size(), m = s.size();
    for(int i = 2; i < n; i++){
        if(height[i] > ans){
            if(sa[i-1] >= 0 && sa[i-1]< m && sa[i]>m)ans = height[i];
            if(sa[i] >= 0 && sa[i] < m && sa[i-1]>m)ans = height[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}

