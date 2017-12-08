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

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        sc(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int A, B, C, AB, AC, BC, ABC;
            scanf("%d%d%d%d%d%d%d", &A, &B, &C, &AB, &BC, &AC, &ABC);
            AB -= ABC, AC -= ABC, BC -= ABC;
            if(AB < 0 || AC < 0 || BC < 0)continue;
            A = A - AB - AC - ABC;
            B = B - AB - BC - ABC;
            C = C - AC - BC - ABC;
            if(A < 0 || B < 0 || C < 0)continue;
            ans = max(ans, A+B+C+AB+AC+BC+ABC);
        }
        printf("%d\n", ans);
    }
    return 0;
}

