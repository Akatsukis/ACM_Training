#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int a[10];
string s;

void solve()
{
    char c;
    for(int i = 0; i < 6; i++){
        if(a[i] > s[7] - '0'){
            c = a[i] + '0';
            s[7] = c;
            cout << s << endl;
            return;
        }
    }
    c = a[0] + '0';
    s[7] = c;
    for(int i = 0; i < 6; i++){
        if(a[i] < 6 && a[i] > s[6] - '0'){
            c = a[i] + '0';
            s[6] = c;
            cout << s << endl;
            return;
        }
    }
    c = a[0] + '0';
    s[6] = c;
    for(int i = 0; i < 6; i++){
        if(a[i] > s[4] - '0'){
            c = a[i] + '0';
            s[4] = c;
            cout << s << endl;
            return;
        }
    }
    c = a[0] + '0';
    s[4] = c;
    for(int i = 0; i < 6; i++){
        if(a[i] < 6 && a[i] > s[3] - '0'){
            c = a[i] + '0';
            s[3] = c;
            cout << s << endl;
            return;
        }
    }
    c = a[0] + '0';
    s[3] = c;
    if(a[0] < 2){
        for(int i = 0; i < 6; i++){
            if(a[i] > s[1] - '0'){
                c = a[i] + '0';
                s[1] = c;
                cout << s << endl;
                return;
            }
        }
    }
    else{
        for(int i = 0; i < 6; i++){
            if(a[i] < 4 && a[i] > s[1] - '0'){
                c = a[i] + '0';
                s[1] = c;
                cout << s << endl;
                return;
            }
        }
    }
    c = a[0] + '0';
    s[1] = c;
    for(int i = 0; i < 6; i++){
        if(a[i] < 3 && a[i] > s[0] - '0'){
            c = a[i] + '0';
            s[0] = c;
            cout << s << endl;
            return;
        }
    }
    c = a[0] + '0';
    s[0] = c;
    cout << s << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        for(int i = 0, j = 0; i < 6; i++, j++){
            if(j == 2 || j == 5)j++;
            a[i] = s[j] - '0';
        }
        sort(a, a + 6);
        solve();
    }
	return 0;
}


