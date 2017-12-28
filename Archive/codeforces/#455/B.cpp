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
const int maxn = 110;
set<int> st[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            st[i].insert(j);
        }
    }
    int cnt = n*(n+1)/2, ans = 0;
    while(cnt){
        ans++;
        for(int i = 0; i < n; ){
            if(st[i].size()){
                set<int>::iterator it = st[i].begin();
                int tmp = *it;
                st[i].erase(it++);
                i = tmp;
                cnt--;
            }
            else i++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

