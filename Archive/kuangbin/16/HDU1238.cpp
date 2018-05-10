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
const int maxn = 110;
char s[maxn][maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n; sc(n);
        for(int i = 0; i < n; i++)scanf("%s", s[i]);
        int len = strlen(s[0]), ans = 0;
        for(int i = 0; i < len; i++){
            for(int j = i+1; j <= len; j++){
                char ch = s[0][j];
                s[0][j] = 0;
                char mat1[maxn], mat2[maxn];
                strcpy(mat1, s[0]+i); strcpy(mat2, s[0]+i);
                s[0][j] = ch;
                reverse(mat2, mat2+(j-i));
                bool flg = 1;
                for(int k = 1; k < n; k++){
                    if(!strstr(s[k], mat1) && !strstr(s[k], mat2)){
                        flg = 0;
                        break;
                    }
                }
                if(flg)ans = max(ans, j-i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

