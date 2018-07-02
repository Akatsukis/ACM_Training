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
int a[maxn];

int main()
{
    int n;
    sc(n);
    int sum = 0;
    for(int i = 0; i < n; i++)sc(a[i]), sum += a[i];
    if(n == 1 || (n == 2 && a[0] == a[1]))printf("-1\n");
    else{
        int now = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            now += a[i];
            ans.pb(i+1);
            if(now*2 != sum)break;
        }
        printf("%d\n", (int)ans.size());
        for(int i = 0; i < (int)ans.size(); i++){
            printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
        }
    }
    return 0;
}

