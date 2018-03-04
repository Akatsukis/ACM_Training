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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int trs(string s)
{
    int ans = 0;
    if(isdigit(s[1])){
        ans += s[1]-'0';
    }
    else ans += s[1]-'a'+10;
    if(isdigit(s[0])){
        ans += 16*(s[0]-'0');
    }
    else ans += 16*(s[0]-'a'+10);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int a, b, c;
    a = trs(s.substr(1, 2));
    b = trs(s.substr(3, 2));
    c = trs(s.substr(5, 2));
    int mn = INF, ansx = 0, ansy = 0, ansz = 0;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            for(int k = 0; k < 16; k++){
                if(sqr(16*i+i-a)+sqr(16*j+j-b)+sqr(16*k+k-c) < mn){
                    mn = sqr(16*i+i-a)+sqr(16*j+j-b)+sqr(16*k+k-c);
                    ansx = i;
                    ansy = j;
                    ansz = k;
                }
            }
        }
    }
    printf("#");
    if(ansx<10)printf("%d", ansx);
    else printf("%c", ansx-10+'a');
    if(ansy<10)printf("%d", ansy);
    else printf("%c", ansy-10+'a');
    if(ansz<10)printf("%d", ansz);
    else printf("%c", ansz-10+'a');
    return 0;
}

