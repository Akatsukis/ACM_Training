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
const int maxn = 1e6+10;
char s[maxn];
int nxt[maxn];
int n;

int get_cyc()
{
    nxt[0] = -1;
    int k = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
    int ret = n-1-nxt[n-1];
    ret = n%ret?n:ret;
    return ret;
}

int mstring(int t)
{
    int i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n){
        if(s[(i+k)%n] == s[(j+k)%n])k++;
        else{
            if(s[(i+k)%n] > s[(j+k)%n]) {
                if(t == 0)i += k+1;
                else j += k+1;
            }
            else{
                if(t == 0)j += k+1;
                else i += k+1;
            }
            if(i == j)j++;
            k = 0;
        }
    }
    return min(i, j)+1;
}

int main()
{
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        int times = n/get_cyc();
        printf("%d %d %d %d\n", mstring(0), times, mstring(1), times);
    }
    return 0;
}

