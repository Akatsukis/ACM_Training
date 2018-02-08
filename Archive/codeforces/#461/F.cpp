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
const int maxn = 3e5+10;
int d[maxn];
bool f[maxn];

int main()
{
    int n, k;
    sc(n);sc(k);
    for(int i = 1; i <= n; i++){
        for(int j = i<<1; j < maxn; j += i)d[j]++;
    }
    int sum = 0, id = 0;
    for(int i = 1; i <= n; i++){
        sum += d[i];
        if(sum >= k){
            id = i;
            break;
        }
    }
    if(sum < k)return !printf("No\n");
    fill(f+1, f+n+1, 1);
    for(int i = 1; i <= id; i++){
        if(d[i] == 1 && id/i <= sum-k){
            f[i] = 0;
            sum -= id/i;
        }
    }
    int ans = 0;
    for(int i = 1; i <= id; i++)ans += f[i];
    printf("Yes\n");
    printf("%d\n", ans);
    for(int i = 1; i <= id; i++)if(f[i])printf("%d ", i);
    printf("\n");
	return 0;
}

