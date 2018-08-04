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
const int maxn = 82;
char s[maxn][maxn];

int main()
{
    int T; sc(T);
    while(T--){
        memset(s, 0, sizeof(s));
        int a, b, c;
        sc(a); sc(b); sc(c);
        int row = b*2+c*2+1, col = a*2+1+b*2;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++)s[i][j] = '.';
        }
        for(int i = 0; i < b*2+1; i++){
            int st = b*2-i;
            if(i%2 == 0){
                int st = b*2-i;
                for(int j = 0; j < c*2+1; j++){
                    if(j%2 == 0){
                        for(int k = 0; k < a*2+1; k++){
                            if(k%2 == 0)s[i+j][st+k] = '+';
                            else s[i+j][st+k] = '-';
                        }
                    }
                    else{
                        for(int k = 0; k < a*2+1; k += 2)s[i+j][st+k] = '|';
                    }   
                }
            }
            else{
                for(int j = 0; j < 2*a+1; j++){
                    if(j%2 == 0)s[i][st+j] = '/';
                    else s[i][st+j] = '.';
                }
            }
        }
        for(int i = 0; i < b; i++){
            for(int j = 0; j < c; j++){
                s[i*2+3+j*2][col-2*i-2] = '/';
                s[i*2+3+j*2-1][col-2*i-2] = '.';
            }
        }
        for(int i = 0; i < row; i++)puts(s[i]);
    }
    return 0;
}


