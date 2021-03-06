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
#include <cstdlib>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REP1(i, n) for(int (i)=1;(i)<=(int)(n);(i)++)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define PI 3.1415926535897932
const ll mod = 1000000007;
const int INF = 2123456789;
const double eps = 1e-7;

template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        for(int i = 0; i < n; i++){
            int foo;
            scanf("%d", &foo);
            while(foo){
                if(foo % 256 == 97)ans++;
                foo /= 256;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
