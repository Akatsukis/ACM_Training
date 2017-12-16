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
const long double eps = 1e-15;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    ll a, b, c;
    scanf("%lld%lld%lld",&a, &b, &c);
    ll now = a*10;
    for(ll i = 1; i <= 1e6; i++){
        for(ll j = 0; j < 10; j++){
            if((j+1)*b > now){
                now = now-j*b;
                now *= 10;
                if(j == c){
                    printf("%d\n", i);
                    return 0;
                }
                //printf("%d\n", j - 1);
                break;
            }
        }
    }
    printf("-1\n");
    return 0;
}

