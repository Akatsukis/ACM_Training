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
//#include <unordered_map>
//#include <unordered_set>

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
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5 + 10;
int a[maxn];
int add[maxn];
set<int, greater<int> > st;
int n;
int main()
{
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(auto it = st.begin(); it != st.end(); it++){
            if(*it < a[i] || cnt > 1)break;
            cnt++;
        }
        if(cnt == 0)add[a[i]]--;
        else if(cnt == 1)add[mx]++;
        st.insert(a[i]);
        mx = max(mx, a[i]);
    }
    int mxadd = -2, ans = 1;
    for(int i = 1; i <= mx; i++){
        if(add[i] > mxadd){
            ans = i;
            mxadd = add[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}

