#include <cstdio>
#include <iostream>
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
#include <bitset>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define PI 3.14159265358979323846
#define debug cout<<"???"<<endl;

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int main()
{
    string s;
    ll num;
    while(cin >> s >> num){
        ll ans1 = 0, ans2 = 0;
        stack<ll> p, q;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                p.push(s[i]-'0');
            }
            else{
                int now;
                if(s[i] == '+')now = 0;
                else now = 1;
                while(!q.empty() && now <= q.top()){
                    int tmp = q.top();q.pop();
                    ll a = p.top();p.pop();
                    ll b = p.top();p.pop();
                    if(tmp == 1)p.push(a*b);
                    else p.push(a+b);
                    //pr(a*b);
                }
                q.push(now);
            }
        }
        while(!q.empty()){
            int tmp = q.top();q.pop();
            ll a = p.top();p.pop();
            ll b = p.top();p.pop();
            if(tmp == 1)p.push(a*b);
            else p.push(a+b);
        }
        ans1 = p.top();p.pop();
        ans2 = s[0] - '0';
        for(int i = 1; i < s.size(); i += 2){
            if(s[i] == '+')ans2 += (ll)s[i+1]-'0';
            else ans2 *= (ll)s[i+1]-'0';
        }
        //cout << ans1 << " " << ans2 << endl;
        if(ans1 == num && ans2 != num)printf("M\n");
        else if(ans1 != num && ans2 == num)printf("L\n");
        else if(ans1 == num && ans2 == num)printf("U\n");
        else if(ans1 != num && ans2 != num)printf("I\n");
    }
    return 0;
}
