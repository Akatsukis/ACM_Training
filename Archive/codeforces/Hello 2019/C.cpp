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
const int maxn = 5e5+10;
int mp[2][maxn];
char s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        int len = strlen(s), now = 0;
        bool ok = 1;
        stack<int> sk;
        for(int j = 0; j < len; j++){
            if(s[j] == '(')sk.push(0);
            else{
                if(sk.empty() || sk.top() == 1)sk.push(1);
                else sk.pop();
            }
        }
        if(sk.empty())cnt++, ok = 0;
        else{
            int t = sk.top();
            while(!sk.empty()){
                if(sk.top() != t)ok = 0;
                else now++;
                sk.pop();
            }
            if(t == 1)now = -now;
        }
        if(ok){
            //printf("i=%d, now=%d\n", i, now);
            if(now > 0){
                if(mp[1][now]){
                    ans++;
                    mp[1][now]--;
                }
                else mp[0][now]++;
            }
            else{
                now = -now;
                if(mp[0][now]){
                    ans++;
                    mp[0][now]--;
                }
                else mp[1][now]++;
            }
            //printf("ans=%d\n", ans);
        }
    }
    printf("%d\n", ans+cnt/2);
    return 0;
}

