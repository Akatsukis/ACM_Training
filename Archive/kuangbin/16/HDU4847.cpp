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
const int maxn = 2e6+10;
char s[maxn];
int n;

void toLower()
{
    for(int i = 0; i < n; i++) {
        if(isupper(s[i]))s[i] = tolower(s[i]);
    }
}

int main()
{
    int ans = 0;
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        toLower();
        for(int i = 0; i < n-3; i++){
            char ch = s[i+4];
            s[i+4] = 0;
            if(!strcmp(s+i, "doge"))ans++;
            s[i+4] = ch;
        }
    }
    printf("%d\n", ans);
    return 0;
}

