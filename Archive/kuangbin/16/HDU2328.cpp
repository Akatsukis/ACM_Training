#include <bits/stdc++.h>
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
const int maxs = 210;
const int maxn = 4e3+10;
char s[maxn][maxs];
char mat[maxs], ans[maxs];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n){
        ans[0] = 0;
        for(int i = 0; i < n; i++)scanf("%s", s[i]);
        int len = strlen(s[0]);
        for(int i = 0; i < len; i++){
            for(int j = i+1; j <= len; j++){
                char ch = s[0][j];
                s[0][j] = 0;
                strcpy(mat, s[0]+i);
                s[0][j] = ch;
                bool flg = 1;
                for(int k = 1; k < n; k++){
                    if(!strstr(s[k], mat)){
                        flg = 0;
                        break;
                    }
                }
                if(flg){
                    if(strlen(mat) > strlen(ans))strcpy(ans, mat);
                    else if(strlen(mat) == strlen(ans) && strcmp(mat, ans) < 0)strcpy(ans, mat);
                }
            }
        }
        if(ans[0] == 0)printf("IDENTITY LOST\n");
        else printf("%s\n", ans);
    }
    return 0;
}

