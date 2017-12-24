#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2010;
int a[maxn][maxn];
int h[maxn];
int l[maxn];
int r[maxn];

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 1; i <= n; i++){
        char s[maxn];
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == '1')a[i][j+1] = 1;
            else a[i][j+1] = 0;
            a[i][j+1] = a[i][j+1]^(i%2)^((j+1)%2);

        }
    }
    int ans = 0, k;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= m;j++){
            if(a[i][j]==1)
                h[j]++;
            else
                h[j]=0;
        }
        h[0]=h[m+1]=-1;
        for(int j=1;j<=m;j++)
        {
            k=j;
            while(h[j]<=h[k-1])
                k=l[k-1];
            l[j]=k;
        }
        for(int j=m;j>=1;j--){
            k=j;
            while(h[j]<=h[k+1])
                k=r[k+1];
            r[j]=k;
        }
        for(int j=1;j<=m;j++){
            ans=max(ans, h[j]*(r[j]-l[j]+1));
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = !a[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= m;j++){
            if(a[i][j]==1)
                h[j]++;
            else
                h[j]=0;
        }
        h[0]=h[m+1]=-1;
        for(int j=1;j<=m;j++)
        {
            k=j;
            while(h[j]<=h[k-1])
                k=l[k-1];
            l[j]=k;
        }
        for(int j=m;j>=1;j--){
            k=j;
            while(h[j]<=h[k+1])
                k=r[k+1];
            r[j]=k;
        }
        for(int j=1;j<=m;j++){
            ans=max(ans, h[j]*(r[j]-l[j]+1));
        }
    }
    printf("%d\n",ans);
    return 0;
}

