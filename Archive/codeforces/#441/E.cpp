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
#define pr(x) printf("x:%d\n", x)
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
int n, m;
vector<int> v[100100];
set<int> in;
set<int> out;

bool solve(int x, int y)
{
    for(int i = x; i < n - 1; i++){
        int j = i == x ? y : 0;
        int sz = min(v[i].size(), v[i + 1].size());
        for(; j < sz; j++){
            if(in.find(v[i][j]) != in.end() && in.find(v[i + 1][j]) != in.end()){
                if(v[i][j] < v[i + 1][j])return solve(x + 1, 0);
                else if(v[i][j] > v[i + 1][j]){
                    return false;
                }
            }
            else if(in.find(v[i][j]) != in.end() && in.find(v[i + 1][j]) == in.end()){
                return solve(x + 1, 0);
            }
            else if(in.find(v[i][j]) == in.end() && in.find(v[i + 1][j]) != in.end()){
                if(v[i][j] > v[i + 1][j])return false;
                else if(v[i][j] < v[i + 1][j]){
                    if(out.find(v[i][j]) != out.end())return false;
                    else{
                        in.insert(v[i][j]);
                        return solve(x + 1, 0);
                    }
                }
            }
            else if(in.find(v[i][j]) == in.end() && in.find(v[i + 1][j]) == in.end() ){
                if(v[i][j] < v[i + 1][j]){
                    out.insert(v[i][j]);
                    out.insert(v[i + 1][j]);
                    if(solve(x + 1, 0))return true;
                    else{
                        out.erase(v[i][j]);
                        out.erase(v[i + 1][j]);
                        in.insert(v[i][j]);
                        in.insert(v[i + 1][j]);
                        return solve(x + 1, 0);
                    }
                }
                else if(v[i][j] > v[i + 1][j]){
                    if(out.find(v[i][j]) != out.end())return 0;
                    else in.insert(v[i][j]);
                    out.insert(v[i + 1][j]);
                    return solve(x + 1, 0);
                }
            }
        }
        if(j == sz && v[i].size() > v[i + 1].size())return 0;
    }
    return true;
}

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        int l;
        sc(l);
        for(int j = 0; j < l; j++){
            int x;
            sc(x);
            v[i].pb(x);
        }
    }
    if(solve(0, 0)){
        printf("Yes\n");
        printf("%d\n", (int)in.size());
        for(auto i = in.begin(); i != in.end(); i++){
            printf("%d ", *i);
        }
        printf("\n");
    }
    else{
        printf("No\n");
    }
	return 0;
}


