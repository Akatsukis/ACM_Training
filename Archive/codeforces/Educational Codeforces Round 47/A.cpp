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
const int maxn = 1e4+10;
int a[maxn], b[maxn];

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < n; i++)sc(a[i]);
    for(int i = 0; i < m; i++)sc(b[i]);
    int ans = 0;
    for(int i = 0, j = 0; i < n && j < m;){
        if(b[j] >= a[i]){
            ans++;
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
