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

int mstring(string &s)
{
    int i = 0, j = 1, k = 0, n = s.size();
    while(i < n && j < n && k < n){
        if(s[(i+k)%n] == s[(j+k)%n])k++;
        else{
            if(s[(i+k)%n] < s[(j+k)%n])j += k+1;
            else i += k+1;
            if(i == j)j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main()
{
    int n;
    while(cin >> n){
        set<string> st;
        for(int i = 0; i < n; i++){
            string s, t;
            cin >> s;
            int k = mstring(s);
            for(int j = 0; j < (int)s.size(); j++)t.pb(s[(k+j)%s.size()]);
            st.insert(t);
        }
        printf("%d\n", (int)st.size());
    }
    return 0;
}

