#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
const int maxn = 1e2+10;
int tot[maxn];
int a[maxn];
char ans[maxn];

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        sc(a[i]); tot[a[i]]++;
    }
    int sum = 0, tmp = 0;
    for(int i = 0; i < maxn; i++){
        if(tot[i] == 1)sum++;
        else if(tot[i] > 2)tmp++;
    }
    if(sum%2 == 1 && !tmp)puts("NO");
    else{
        puts("YES");
        int u = 0, v = 0;
        for(int i = 0; i < n; i++){
            if(tot[a[i]] == 1){
                if(u == v)ans[i] = 'A', u++;
                else ans[i] = 'B', v++;
            }
        }
        if(u != v){
            for(int i = 0; i < n; i++){
                if(tot[a[i]] > 2){
                    ans[i] = 'B';
                    for(int j = i+1; j < n; j++){
                        if(a[j] == a[i])ans[j] = 'A';
                    }
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!ans[i])ans[i] = 'A';
        }
        printf("%s\n", ans);
    }
    return 0;
}

