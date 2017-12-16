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
const int maxn = 5e3+10;
char s[maxn][maxn];
int vis[30];
int cur[30];
bool flag;
int n, k;
vector<int> v[maxn];

bool check(int x, int y)
{
    for(int i = 1; i < k; i++){
        int cnt = 0;
        if(s[0][x] != s[i][x])cnt++;
        if(s[0][y] != s[i][y])cnt++;
        for(int j = 0; j < (int)v[i].size(); j++){
            int u = v[i][j];
            if(u == x || u == y)continue;
            if(s[0][u] != s[i][u])cnt++;
        }
        if(cnt != 2 && !(cnt == 0 && flag == 1))return 0;
    }
    return 1;
}

int main()
{
    sc(k);sc(n);
    for(int i = 0; i < k; i++){
        scanf("%s", s[i]);
    }
    for(int i = 0; i < n; i++){
        if(vis[s[0][i] - 'a']){
            flag = 1;
        }
        vis[s[0][i] - 'a']++;
    }
    for(int i = 1; i < k; i++){
        memset(cur, 0, sizeof(cur));
        for(int j = 0; j < n; j++){
            cur[s[i][j]-'a']++;
            if(s[i][j] != s[0][j]){
                v[i].pb(j);
            }
        }
        if(v[i].size() > 4){
            printf("-1\n");
            return 0;
        }
        for(int i = 0; i < 26; i++){
            if(cur[i] != vis[i]){
                //printf("vis[%c]:%d\n", i+'a', vis[i]);
                //printf("cur[%c]:%d\n", i+'a', cur[i]);
                printf("-1\n");
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(s[0][i], s[0][j]);
            if(check(i, j)){
                printf("%s\n", s[0]);
                return 0;
            }
            swap(s[0][i], s[0][j]);
        }
    }
    printf("-1\n");
    return 0;
}
