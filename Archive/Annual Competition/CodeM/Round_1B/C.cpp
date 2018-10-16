#include <bits/stdc++.h>
#include <stdlib.h>
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
#define lowbit(x) ((x)&(-(x)))
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxs = 2e4+10;
char s[maxs];

int f(int l, int r)
{
    if(l >= r)return 0;
    else if(r-lowbit(r) >= l)return f(l, r-lowbit(r))+1;
    else return f(l, r-1)+1;
}

int main()
{
    while(scanf("%s", s) != EOF){
        if(!strcmp(s, "1")){
            printf("1\n");
            continue;
        }
        int n = strlen(s);
        int ans = n*(n-1)/2;
        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                bool flg = 1;
                for(int j = i; j < n; j++){
                    if(s[j] != '1'){
                        flg = 0;
                        break;
                    }
                }
                if(flg)ans += n-i;
                else ans += n-i-1;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

