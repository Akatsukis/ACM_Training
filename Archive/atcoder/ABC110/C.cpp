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
const int maxn = 1e5+10;
int flt[maxn];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    bool flg = 1;
    set<int> st;
    for(int i = 0; i < n; i++){
        if(!flt[(int)s[i]]){
            if(st.count(t[i])){
                flg = 0;
                break;
            }
            else{
                flt[(int)s[i]] = t[i];
                st.insert(t[i]);
            }   
        }
        else if(flt[(int)s[i]] != t[i]){
            flg = 0;
            break;
        }
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}

