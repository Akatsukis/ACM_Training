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
set<int> ans;

bool check(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
    return false;
}

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    stack<pii> cnt;
    for(int i = 0; i < n; i++){
        if(check(s[i])){
            while(!cnt.empty())cnt.pop();
        }
        else{
            //cnt.push(mk(s[i], i));
            if(cnt.empty()){
                if(i + 1 < n && s[i + 1] == s[i]){
                    int now = i;
                    while(i < n && s[i] == s[now])i++;
                    i--;
                    if(i + 1 < n && !check(s[i + 1]))ans.insert(i);
                    while(!cnt.empty())cnt.pop();
                }
                else cnt.push(mk(0, i));
            }
            else if((int)cnt.size() == 1){
               if(i + 1 < n && s[i + 1] == s[i]){
                    ans.insert(cnt.top().se);
                    while(!cnt.empty())cnt.pop();
                    int now = i;
                    while(i < n && s[i] == s[now])i++;
                    i--;
                    if(i + 1 < n && !check(s[i + 1]))ans.insert(i);
                    while(!cnt.empty())cnt.pop();
               }
               else cnt.push(mk(s[i], i));
            }
            else{
                ans.insert(cnt.top().se);
                while(!cnt.empty())cnt.pop();
                if(i + 1 < n && s[i + 1] == s[i]){
                    int now = i;
                    while(i < n && s[i] == s[now])i++;
                    i--;
                    if(i + 1 < n && !check(s[i + 1]))ans.insert(i);
                    while(!cnt.empty())cnt.pop();
               }
               else cnt.push(mk(s[i], i));
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << s[i];
        if(i != n - 1 && ans.count(i))cout << " ";
    }
    cout << endl;
	return 0;
}


