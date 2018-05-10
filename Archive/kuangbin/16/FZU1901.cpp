#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
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
const int maxn = 1e6+10;
char s[maxn];
int nxt[maxn];
int n;

void get_next()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%s", s);
        n = strlen(s);
        get_next();
        vector<int> ans;
        int k = nxt[n-1];
        while(k != -1){
            ans.pb(n-k-1);
            k = nxt[k];
        }
        ans.pb(n);
        printf("Case #%d: %d\n", kase++, (int)ans.size());
        for(int i = 0; i < (int)ans.size(); i++){
            printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
        }
    }
    return 0;
}

