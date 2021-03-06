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
const int maxn = 1e6+10;
char s[maxn], t[maxn];
struct token
{
    int type, pos;
}tk[maxn];

int main()
{
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    if(n != m){
        printf("-1\n");
        return 0;
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        if(t[i] == 'L'){
            tk[num].type = 0;
            tk[num].pos = i;
            num++;
        }
        if(t[i] == 'R'){
            tk[num].type = 1;
            tk[num].pos = i;
            num++;
        }
    }
    int now = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            if(tk[now].type == 1 || tk[now].pos > i){
                printf("-1\n");
                return 0;
            }
            else{
                ans += i - tk[now].pos;
                now++;
            }
        }
        if(s[i] == 'R'){
            if(tk[now].type == 0 || tk[now].pos < i){
                printf("-1\n");
                return 0;
            }
            else{
                ans += tk[now].pos - i;
                now++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

