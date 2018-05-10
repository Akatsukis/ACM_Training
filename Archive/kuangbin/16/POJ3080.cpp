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
const int maxn = 20;
const int maxm = 70;
char s[maxn][maxm];
char ans[maxm];

int main()
{
    int T;
    sc(T);
    while(T--){
        ans[0] = 0;
        int n;
        sc(n);
        for(int i = 0; i < n; i++)scanf("%s", s[i]);
        for(int i = 0; i < 60; i++){
            for(int j = i+1; j <= 60; j++){
                char tmp[maxm];
                char ch = s[0][j];
                s[0][j] = 0;
                strcpy(tmp, s[0]+i);
                s[0][j] = ch;
                bool flg = 1;
                for(int k = 1; k < n; k++){
                    if(!strstr(s[k], tmp)){
                        flg = 0;
                        break;
                    }
                }
                if(flg){
                    if(strlen(tmp) > strlen(ans))strcpy(ans, tmp);
                    else if(strlen(tmp) == strlen(ans) && strcmp(tmp, ans) < 0)strcpy(ans, tmp);
                }
            }
        }
        if(strlen(ans) < 3)printf("no significant commonalities\n");
        else printf("%s\n", ans);
    }
    return 0;
}

