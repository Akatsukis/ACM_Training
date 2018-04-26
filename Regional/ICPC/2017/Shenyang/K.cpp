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
#include <bitset>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A,end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x"=%d\n")
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",sdtin)
#define freout freopen("out.txt","w",stdout)
#define debug cout<<"???"<<endl
#define PI 3.14159265358979323846

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

const int maxn = 50;

char s[maxn];
int main()
{
    int T; sc(T);
    while(T--){
        scanf("%s", s);
        int len = strlen(s);
        if(len == 1 && s[0] <= '4'){
            printf("%d\n", 4);
            continue;
        }
        int m = 0, p = -1;
        for(int i = 0; i < len; i++) m = (m+s[i]-'0')%3;
        if(m == 0){
            for(int i = len-1; i >= 0; i--){
                if(s[i] < '9'){
                    s[i]++;
                    break;
                }else{
                    s[i] = '0';
                    if(i == 0) p = 1;
                }
            }
        }
        if(p >= 0) printf("%d", p);
        printf("%s\n", s);
    }
    return 0;
}
