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
const int maxn = 1e5+10;
char s[maxn];
char t[maxn];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    bool flg = 1;
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '2')break;
        if(flg && s[i] == '0')ans++;
    }
    for(int i = 0; i < ans; i++){
        t[cnt++] = '0';
    }
    ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')ans++;
    }
    for(int i = 0; i < ans; i++){
        t[cnt++] = '1';
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '2'){
            for(int j = i; j < n; j++){
                if(s[j] != '1')t[cnt++] = s[j];
            }
            break;
        }
    }
    t[cnt] = 0;
    printf("%s\n", t);
    return 0;
}
