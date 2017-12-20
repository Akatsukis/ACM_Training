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
int a[30];
int month[] = {
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        sc(a[i]);
    }
    bool flag;
    for(int i = 0; i < 36; i++){
        flag = 1;
        for(int j = 0; j < n; j++){
            if(month[(i+j)%36] != a[j]){
                flag = 0;
                break;
            }
        }
        if(flag)break;
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}

