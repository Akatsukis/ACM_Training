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
const int maxn = 1e5+10;
char s[maxn];

int main()
{
    fgets(s, maxn, stdin);
    int n = strlen(s);
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            if(cnt)ans++;
            else cnt++;
        }
        else if(s[i] == ')'){
            if(cnt)cnt--;
            else ans++;
        }
        else if(s[i] != ' ' && !isalpha(s[i]))ans += cnt, cnt = 0;
    }
    ans += cnt;
    printf("%d\n", ans);
    return 0;
}

