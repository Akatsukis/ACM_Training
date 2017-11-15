#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int nxt[30];
int pre[30];
vector<string> v;
bool vis[30];
bool has[30];

int main()
{
    fill(nxt, nxt + 26, -1);
    fill(pre, pre + 26, -1);
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j + 1 < (int)s.size(); j++){
            if((nxt[s[j]-'a'] == s[j+1]-'a' || nxt[s[j]-'a'] == -1) && (pre[s[j+1]-'a'] == s[j]-'a' || pre[s[j+1]-'a'] == -1)){
                nxt[s[j]-'a'] = s[j+1]-'a';
                pre[s[j+1]-'a'] = s[j]-'a';
            }
            else{
                printf("NO\n");
                return 0;
            }
        }
        if(s.size() == 1){
            has[s[0]-'a'] = 1;
        }
    }
    for(int i = 0; i < 26; i++){
        //printf("pre[%c]:%c nxt[%c]:%c\n", i+'a', pre[i]+'a', i+'a', nxt[i]+'a');
        if(pre[i] == -1 && nxt[i] != -1){
            int now = i;
            string res;
            while(now != -1){
                res.pb((char)(now+'a'));
                vis[now] = 1;
                now = nxt[now];
            }
            v.pb(res);
        }
    }
    for(int i = 0; i < 26; i++){
        int now = nxt[i];
        while(now != -1){
            if(now == i){
                printf("NO\n");
                return 0;
            }
            now = nxt[now];
        }
    }
    for(int i = 0; i < 26; i++){
        if(has[i] && !vis[i]){
            string now;
            now.pb((char)(i+'a'));
            v.pb(now);
        }
    }
    sort(ALL(v));
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i];
    }
    cout << endl;
    return 0;
}

