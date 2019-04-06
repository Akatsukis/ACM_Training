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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int mp[maxn][maxn];
int row[maxn];
int col[maxn];
int n, m, r, c;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%d%d%d%d", &n, &m, &r, &c);
        int tot = 0;
        for(int i = 1; i <= n; i++){
            char s[maxn];
            scanf("%s", s+1);
            for(int j = 1; j <= m; j++){
                if(s[j] == '@')mp[i][j] = 1, tot++;
                else mp[i][j] = 0;
            }
        }
        if(tot%(r+1)*(c+1) != 0){
            printf("Case #%d: IMPOSSIBLE\n", kase++);
            continue;
        }
        int hrz = tot/(r+1), vtc = tot/(c+1);
        for(int i = 1; i <= n; i++){
            int now = 0;
            for(int j = 1; j <= m; j++){
                now += mp[i][j];
            }
            row[i] = now;
        }
        for(int j = 1; j <= m; j++){
            int now= 0;
            for(int i = 1; i <= n; i++){
                now +=mp[i][j];
            }
            col[j] = now;
        }
        bool flg = 1;
        vector<int> v1, v2;
        v1.pb(0); v2.pb(0);
        int now = 0;
        for(int i = 1; i <= n; i++){
            now += row[i];
            if(now == hrz)now = 0, v1.pb(i);
            else if(now > hrz){
                flg = 0;
                break;
            }
        }
        if(!flg){
            printf("Case #%d: IMPOSSIBLE\n", kase++);
            continue;
        }
        now = 0;
        for(int j = 1; j <= m; j++){
            now += col[j];
            if(now == vtc)now = 0, v2.pb(j);
            else if(now > vtc){
                flg = 0;
                break;
            }
        }
        if(!flg){
            printf("Case #%d: IMPOSSIBLE\n", kase++);
            continue;
        }
        int per = tot/((r+1)*(c+1));
        for(int i = 1; i < (int)v1.size(); i++){
            //printf("v1[%d]=%d\n", i, v1[i]);
            for(int j = 1; j < (int)v2.size(); j++){
                //printf("v2[%d]=%d\n", j, v2[j]);
                int now = 0;
                for(int u = v1[i-1]+1; u <= v1[i]; u++){
                    for(int v = v2[j-1]+1; v <= v2[j]; v++){
                        now += mp[u][v];
                    }
                }
                if(now != per){
                    flg = 0;
                    break;
                }
            }
            if(!flg)break;
        }
        if(!flg)printf("Case #%d: IMPOSSIBLE\n", kase++);
        else printf("Case #%d: POSSIBLE\n", kase++);
    }
    return 0;
}

