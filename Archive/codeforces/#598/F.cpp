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
int num[26];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int rev = 0, flg = 0;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) {
            for(int j = s[i]-'a'+1; j < 26; j++) {
                rev += num[j];
            }
            num[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(num[i] >= 2) flg = 1;
        }
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) {
            for(int j = t[i]-'a'+1; j < 26; j++) {
                rev += num[j];
            }
            num[t[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(num[i] >= 2) flg = 1;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s != t || (rev%2 != 0 && !flg)) puts("NO");
        else puts("YES");
    }
    return 0;
}

