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
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        num[s[i]-'a']++;
    }
    bool flg = 1;
    for(int i = 0; i < 26; i++){
        if(num[i] == 1)flg = 0;
    }
    if(flg || n == 1)puts("Yes");
    else{
        for(int i = 0; i < 26; i++){
            if(num[i] >= 2)flg = 1;
        }
        if(flg)puts("Yes");
        else puts("No");
    }
    return 0;
}


