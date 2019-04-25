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

int main()
{
    int cur = 0;
    set<int> st;
    for(int i = 0; i < 30; i++){
        cur = cur<<1|1;
        st.insert(cur);
    }
    int n;
    scanf("%d", &n);
    int ans = 0;
    vector<int> vec;
    while(!st.count(n)){
        ans++;
        for(int i = 30; i >= 0; i--){
            if(n>>i&1){
                n ^= (1<<(i+1))-1;
                vec.push_back(i+1);
                break;
            }
        }
        if(st.count(n))break;
        else ans++, n++;
    }
    printf("%d\n", ans);
    for(int i = 0; i < (int)vec.size(); i++){
        printf("%d%c", vec[i], " \n"[i==(int)vec.size()-1]);
    }
    return 0;
}

