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

int main()
{
    int n;
    scanf("%d", &n);
    set<int> enter, leave;
    vector<int> ans;
    int cnt = 0;
    bool flg = 1;
    for(int i = 0; i < n; i++) {
        cnt++;
        int x;
        scanf("%d", &x);
        if(x > 0) {
            if(!enter.count(x)) {
                enter.insert(x);
            }
            else {
                flg = 0;
                break;
            }
        }
        else {
            x = -x;
            if(!enter.count(x)) {
                flg = 0;
                break;
            }
            else if(!leave.count(x)){
                leave.insert(x);
            }
            else {
                flg = 0;
                break;
            }
        }
        if(enter.size() == leave.size()) {
            enter.clear(); 
            leave.clear();
            ans.push_back(cnt);
            cnt = 0;
        }
    }
    if(enter.size() || leave.size()) flg = 0;
    if(flg) {
        int m = ans.size();
        printf("%d\n", m);
        for(int i = 0; i < m; i++) {
            printf("%d%c", ans[i], " \n"[i==m-1]);
        }
    }
    else puts("-1");
    return 0;
}

