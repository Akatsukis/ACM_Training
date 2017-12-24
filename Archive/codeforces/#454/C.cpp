#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
char t[maxn][3];
string s[maxn];
bool ans[maxn];
bool vis[maxn];
set<int> v;

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%s", t[i]);
        cin >> s[i];
    }
    bool flag = 1;
    int c = 0, res = 0;
    for(int i = 0; i < 26; i++){
        ans[i] = 1;
    }
    for(int i = 0; i < n; i++){
        if(flag){
            if(t[i][0] == '!'){
                v.clear();
                for(int j = 0; j <(int)s[i].size(); j++){
                    v.insert(s[i][j]-'a');
                }
                for(int j = 0; j < 26; j++){
                    if(ans[j] == 1 && v.count(j)){
                        ans[j] = 1;
                    }
                    else ans[j] = 0;
                }
            }
            if(t[i][0] == '.'){
                for(int j = 0; j < (int)s[i].size(); j++){
                    vis[s[i][j]-'a'] = 1;
                }
            }
            if(t[i][0] == '?'){
                vis[s[i][0]-'a'] = 1;
            }
            int cnt = 0;
            for(int j = 0; j < 26; j++){
                if(ans[j] && !vis[j]){
                    cnt++;
                    c = j;
                }
            }
            if(cnt == 1){
                flag = 0;
            }
        }
        else{
            if(t[i][0] == '!')res++;
            else if(t[i][0] == '?' && s[i][0]-'a' != c)res++;
        }
    }
    //printf("%c\n", c);
    printf("%d\n", res);
    return 0;
}

