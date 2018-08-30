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
string s[2];

bool check(string &t)
{
    for(int i = 0; i < SZ(t); i++)if(t[i] > '1')return 1;
    return 0;
}

int main()
{
    cin >> s[0];
    int n = s[0].size();
    int cur = 0, nxt = 1;
    while(check(s[cur])){
        s[nxt].clear();
        for(int i = 0; i < n; i++)s[nxt] += "0";
        for(int i = 0; i < n; i++){
            if(s[cur][i] == '1' || s[cur][i] == '3')s[nxt][i]++;
            if(s[cur][i] == '2' || s[cur][i] == '3'){
                if(i-1 >= 0)s[nxt][i-1]++;
                if(i+1 < n)s[nxt][i+1]++;
            }
        }
        swap(cur, nxt);
    }
    cout << s[cur] << endl;
    return 0;
}


