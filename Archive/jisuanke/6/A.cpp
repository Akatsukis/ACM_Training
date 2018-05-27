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
const int maxn = 1e6+10;
int a[maxn];
set<int> st;

int main()
{
    a[1] = 1;
    st.insert(1);
    for(int i = 2; a[i-1] < 1e9; i++){
        a[i] = a[i-1]+i+1;
        st.insert(a[i]);
    }
    int n, m;
    sc(n);
    for(int i = 0; i < n; i++){
        sc(m);
        bool flg = 1;
        for(int j = 0; j < m; j++){
            int u; sc(u);
            if(!st.count(u))flg = 0;
        }
        if(flg)puts("yes");
        else puts("no");
    }
    return 0;
}

