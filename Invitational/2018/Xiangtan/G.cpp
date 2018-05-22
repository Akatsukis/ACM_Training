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
const int maxn = 1e4+10;
char s[maxn], t[maxn];
vector<int> v1, v2;

int main()
{
    while(scanf("%s%s", s, t)  != EOF){
        v1.clear(), v2.clear();
        int n = strlen(s), m = strlen(t);
        int now1 = 0, now2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'c')v1.pb(now1), v1.pb(now2), now1 = now2 = 0;
            else if(s[i] == 'a')now1++;
            else now2++;
        }
        v1.pb(now1), v1.pb(now2), now1 = now2 = 0;
        for(int i = 0; i < m; i++){
            if(t[i] == 'c')v2.pb(now1), v2.pb(now2), now1 = now2 = 0;
            else if(t[i] == 'a')now1++;
            else now2++;
        }
        v2.pb(now1), v2.pb(now2), now1 = now2 = 0;
        if(v1.size() != v2.size())puts("No");
        else{
            bool flg = 1;
            for(int i = 0; i < (int)v1.size(); i++){
                if((v1[i]-v2[i])%2 != 0){
                    flg = 0;
                    break;
                }
            }
            if(flg)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

