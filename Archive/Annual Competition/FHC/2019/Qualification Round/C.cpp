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
const int maxn = 3e2+10;
char s[maxn];

int calc(int x) {
    stack<char> opt;
    stack<int> val;
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        if(tolower(s[i]) == 'x' || isdigit(s[i])) {
            if(s[i] == 'x')val.push(x);
            else if(s[i] == 'X')val.push(!x);
            else val.push(s[i]-'0');
            while(!opt.empty() && opt.top() != '(') {
                char c = opt.top(); opt.pop();
                int v1 = val.top(); val.pop();
                int v2 = val.top(); val.pop();
                if(c == '&')val.push(v1&v2);
                if(c == '|')val.push(v1|v2);
                if(c == '^')val.push(v1^v2);
            }
        }
        else {
            if(s[i] == ')') {
                opt.pop();
                while(!opt.empty() && opt.top() != '(') {
                    char c = opt.top(); opt.pop();
                    int v1 = val.top(); val.pop();
                    int v2 = val.top(); val.pop();
                    if(c == '&')val.push(v1&v2);
                    if(c == '|')val.push(v1|v2);
                    if(c == '^')val.push(v1^v2);
                }
            }
            else opt.push(s[i]);
        }
    }
    return val.top();
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        printf("Case #%d: ", kase++);
        int v1 = calc(0);
        int v2 = calc(1);
        if(v1 == v2)puts("0");
        else puts("1");
    }
    return 0;
}

