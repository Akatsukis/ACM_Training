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
const int maxn = 3e5+10;
char s[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        vector<int> odd, even;
        for(int i = 0; i < n; i++) {
            int digit = s[i]-'0';
            if(digit%2 == 0) {
                even.push_back(digit);
            }
            else {
                odd.push_back(digit);
            }
        }
        string s;
        int i = 0, j = 0;
        for(; i < (int)odd.size() && j < (int)even.size();) {
            if(odd[i] < even[j]) {
                char c = '0'+odd[i];
                s += c;
                i++;
            }
            else {
                char c = '0'+even[j];
                s += c;
                j++;
            }
        }
        while(i < (int)odd.size()) {
            char c = '0'+odd[i];
            s += c;
            i++;
        }
        while(j < (int)even.size()) {
            char c = '0'+even[j];
            s += c;
            j++;
        }
        printf("%s\n", s.c_str());
    }
    return 0;
}

