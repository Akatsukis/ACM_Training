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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, k;
const int maxn = 1e5+10;
char s[maxn];
char ans[maxn];
int vis[maxn];

int main()
{
    scanf("%d%d%s", &n, &k, s);
    int mx = -1, mn = 27;
    for(int i = 0; i < n; i++){
        if(s[i]-'a' > mx)mx = s[i]-'a';
        if(s[i]-'a' < mn)mn = s[i]-'a';
        vis[s[i]-'a'] = 1;
    }
    if(k > n){
        printf("%s", s);
        for(int i = 0; i < k-n; i++){
            printf("%c", mn+'a');
        }
        printf("\n");
        return 0;
    }
    else{
        int pos = n-1;
        for(int i = k-1; i >= 0; i--){
            if(s[i]-'a' != mx){
                pos = i;
                break;
            }
        }
        for(int i = 0; i < pos; i++)printf("%c", s[i]);
        for(int i = s[pos]-'a'+1; i < 26; i++){
            if(vis[i]){
                printf("%c", i+'a');
                break;
            }
        }
        for(int i = pos+1; i < k; i++)printf("%c", mn+'a');
        printf("\n");
    }
    return 0;
}

