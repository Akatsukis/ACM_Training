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

struct cmp
{
    bool operator()(const string &lhs, const string &rhs)const
    {
        if(lhs.size() != rhs.size())return lhs.size() > rhs.size();
        else return lhs < rhs;
    }
};

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        string s[n];
        for(int i = 0; i < n; i++)cin >> s[i];
        map<string, vector<int>, cmp> mp;
        for(int i = 0; i < n; i++){
            string t;
            for(int j = (int)s[i].size()-1; j >= 0; j--){
                t = s[i][j]+t;
                mp[t].push_back(i);
            }
        }
        int ans = 0;
        set<int> st;
        for(auto it: mp){
            int u = -1, v = -1;
            for(auto w : it.second){
                if(!st.count(w)){
                    if(u == -1)u = w;
                    else if(v == -1){
                        v = w;
                        break;
                    }
                }
            }
            if(u != -1 && v != -1){
                st.insert(u); st.insert(v);
                ans += 2;
            }
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

