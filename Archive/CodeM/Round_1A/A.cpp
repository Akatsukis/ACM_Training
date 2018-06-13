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
#define Abs(x) (((x)>=0)?(x):(-(x)))
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
int mp[10][10];
int word[26];
char s[maxn];

void init()
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            mp[i][j] = Abs(i/3-j/3)+Abs(i%3-j%3);
        }
    }
    for(int i = 0; i < 3; i++)word[i] = 1;
    for(int i = 3; i < 6; i++)word[i] = 2;
    for(int i = 6; i < 9; i++)word[i] = 3;
    for(int i = 9; i < 12; i++)word[i] = 4;
    for(int i = 12; i < 15; i++)word[i] = 5;
    for(int i = 15; i < 19; i++)word[i] = 6;
    for(int i = 19; i < 22; i++)word[i] = 7;
    for(int i = 22; i < 26; i++)word[i] = 8;

}

int main()
{
    int T;
    sc(T);
    init();
    while(T--){
        scanf("%s", s);
        int pre = 0, ans = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            ans += mp[pre][word[s[i]-'A']];
            pre = word[s[i]-'A'];
        }
        printf("%d\n", ans);
    }
    return 0;
}

