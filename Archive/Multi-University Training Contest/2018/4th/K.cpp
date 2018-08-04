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
const int maxn = 510;
char s[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        scanf("%s", s);
        int n = strlen(s);
        bool flg = 1;
        for(int i = 0; i+1 < n; i++){
            if(s[i] == '0'){
                if(isdigit(s[i+1])){
                    if(i == 0 || !isdigit(s[i-1])){
                        flg = 0;
                        break;
                    }  
                }
                if(s[i+1] == '?'){
                    if(i == 0 || !isdigit(s[i-1]))s[i+1] = '+';
                    else s[i+1] = '1';
                }
            }   
            else if(s[i] == '+' || s[i] == '*'){
                if(s[i+1] == '+' || s[i+1] == '*'){
                    flg = 0;
                    break;
                }
            }
            else if(s[i] == '?')s[i] = '1';
        }
        if(s[n-1] == '?')s[n-1] = '1';
        if(s[0] == '+' || s[0] == '*' || s[n-1] == '+' || s[n-1] == '*')flg = 0;
        if(!flg)puts("IMPOSSIBLE");
        else puts(s);
    }
    return 0;
}


