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
char s[10][30];
string ans;

void check(int y)
{
    if(s[0][y+1]=='X'){
        if(s[1][y]=='X'){
            if(s[1][y+3]=='X'){
                if(s[3][y+1]=='.')ans.pb('0');
                else{
                    if(s[4][y]=='X')ans.pb('8');
                    else ans.pb('9');
                }
            }
            else{
                if(s[4][y]=='X')ans.pb('6');
                else ans.pb('5');
            }
        }
        else{
            if(s[4][y]=='X')ans.pb('2');
            else{
                if(s[3][y+1]=='X')ans.pb('3');
                else ans.pb('7');
            }
        }
    }
    else{
        if(s[1][y]=='X')ans.pb('4');
        else ans.pb('1');
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        ans.clear();
        for(int i = 0; i < 7; i++){
            scanf("%s", s[i]);
        }
        check(0);
        check(5);
        ans.pb(':');
        check(12);
        check(17);
        cout << ans << endl;
    }
    return 0;
}

