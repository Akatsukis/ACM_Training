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
const int maxn = 1e2+10;
char s[maxn];
int num[26];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        memset(num, 0, sizeof(num));
        scanf("%s", s);
        int n = strlen(s);
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++){
            num[s[i]-'a']++;
            if((s[i]-'a')%2)odd++;
            else even++;
        }
        if(!odd | !even){
            puts(s);
            continue;
        }
        bool ok = 0;
        char u = 0, v = 0;
        for(int i = 0; i < 26; i += 2){
            for(int j = 1; j < 26; j += 2){
                if(num[i] && num[j] && abs(i-j) != 1){
                    ok = 1;
                    u = i+'a', v = j+'a';
                    num[i]--; num[j]--;
                    break;
                }
            }
            if(ok)break;
        }
        if(ok){
            string ans;
            for(int i = 0; i < 26; i += 2){
                for(int j = 0; j < num[i]; j++){
                    char c = i+'a';
                    ans += c;
                }
            }
            ans += u; ans += v;
            for(int i = 1; i < 26; i += 2){
                for(int j = 0; j < num[i]; j++){
                    char c = i+'a';
                    ans += c;
                }
            }
            puts(ans.c_str());
        }
        else puts("No answer");
    }
    return 0;
}

