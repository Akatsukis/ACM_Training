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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
const int maxs = 130;
int buc[maxn], x[maxn], y[maxn], sa[maxn], rk[maxn], height[maxn];
int st[maxn][30];

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
        p = 1, x[sa[0]] = 0;
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
    height[0] = 0;
    height[len] = 0;
}

void init_st(int len)
{
    for(int i = 0; i < len; i++)st[i][0] = height[i];
    for(int j = 1; (1<<j) <= len; j++){
        for(int i = 1; i+(1<<j)-1 < len; i++){
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}

int lcp(int l, int r)
{
    int k = log2(r-l+1);
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        int k;
        string s;
        cin >> k >> s;
        int sz = s.size();
        build_sa(s);
        init_st(sz+1);
        int ans = 0;
        if(k == 1){
            for(int i = 1; i <= sz; i++){
                ans += (sz-sa[i-1])-max(height[i], height[i-1]);
            }
        }
        else{
            for(int i = k; i <= sz; i++){
                ans += lcp(i-k+1, i-1)-max(lcp(i-k+1, i), lcp(i-k, i-1));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

