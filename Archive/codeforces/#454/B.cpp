#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
char s[20][20];

void solve(int x, int y)
{
    //pr(x);pr(y);
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 3 || j == 6)continue;
            if(s[i+x][j+y] == '.'){
                cnt++;
                s[i+x][j+y] = '!';
            }
        }
    }
    if(cnt)return;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 11; j++){
            if(j == 3 || j == 7)continue;
            if(s[i][j] == '.'){
                s[i][j] = '!';
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 9; i++){
        gets(s[i]);
        if(i == 2 || i == 5)gets(s[15]);
    }
    int x, y;
    sc(x);sc(y);
    x--; y--;
    x -= x/3*3;
    y -= y/3*3;
    solve(x*3, y*3+y);
    for(int i = 0; i < 9; i++){
        printf("%s\n", s[i]);
        if(i == 2 || i == 5)printf("\n");
    }
    return 0;
}

