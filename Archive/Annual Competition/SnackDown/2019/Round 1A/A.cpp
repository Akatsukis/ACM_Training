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

int id(char c)
{
    if(c == 'd' || c == 'f')return 0;
    else return 1;
}

int main()
{
    int T; sc(T);
    while(T--){
        int n;
        sc(n);
        int ans = 0;
        set<string> st;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            int now = 2, pre = id(s[0]);
            for(int j = 1; j < (int)s.size(); j++){
                if(id(s[j]) == pre)now += 4;
                else now += 2;
                pre = id(s[j]);
            }
            if(st.count(s))ans += now/2;
            else ans += now, st.insert(s);
        }
        printf("%d\n", ans);
    }
    return 0;
}

