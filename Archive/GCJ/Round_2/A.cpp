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
const int maxn = 110;
char ans[maxn][maxn];
int a[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(ans, 0, sizeof(ans));
        int n;
        sc(n);
        for(int i = 1; i <= n; i++)sc(a[i]);
        if(!a[1] || !a[n]){
            printf("Case #%d: IMPOSSIBLE\n", kase++);
            continue;
        }
        int ret = 1, now = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < a[i]; j++){
                if(now == i){
                    now++;
                    continue;
                }
                else if(now < i){
                    ret = max(ret, i-now+1);
                    for(int k = now; k < i; k++){
                        ans[k-now][k] = '\\';
                    }
                }
                else{
                    ret = max(ret, now-i+1);
                    for(int k = now; k > i; k--){
                        ans[now-k][k] = '/'; 
                    }
                }
                now++;
            }
        }
        printf("Case #%d: %d\n", kase++, ret);
        for(int i = 0; i < ret; i++){
            for(int j = 1; j <= n; j++){
                if(!ans[i][j])ans[i][j] = '.';
            }
            puts(ans[i]+1);
        }
    }   
    return 0;
}

