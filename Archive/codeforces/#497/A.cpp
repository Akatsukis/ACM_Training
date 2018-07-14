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
set<char> st;

int main()
{
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    string s;
    cin >> s;
    bool flg = 1;
    int sz = (int)s.size();
    for(int i = 0; i < sz-1; i++){
        if(s[i] != 'n' && !st.count(s[i]) && !st.count(s[i+1]))flg = 0;
    }
    if(s[sz-1] != 'n' && !st.count(s[sz-1]))flg = 0;
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}

