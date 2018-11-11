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
const int maxn = 26;
int num[maxn];

bool check(string s)
{
    memset(num, 0, sizeof(num));
    for(auto c : s)num[c-'a']++;
    for(int i = 0; i < maxn; i++){
        if(num[i]*2 > (int)s.size())return 0;
    }
    return 1;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    bool flg = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            string t = s.substr(i, j);
            if(check(t)){
                puts("YES");
                cout << t << endl;
                flg = 1;
                break;
            }
        }
        if(flg)break;
    }
    if(!flg)puts("NO");
    return 0;
}

