#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
int num[maxn];
char s[maxn];
int sum[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    scanf("%s", s);
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1];
        if(s[i-1]=='1')sum[i]++;
    }
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        int l = i, r = num[i];
        if(l > r)swap(l, r);
        if(sum[r-1]-sum[l-1]!=r-l){
            flag = 0;
            break;
        }
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
	return 0;
}

