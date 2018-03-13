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
#include <bitset>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A,end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x"=%d\n")
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",sdtin)
#define freout freopen("out1.txt","w",stdout)
#define debug cout<<"???"<<endl
#define PI 3.14159265358979323846

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

const int maxn = 1e7;

int main()
{
    freout;
    ll pre = 0;
    for(ll k = 0, t = 2; t <= maxn; t++){
        ll p = t*t;
        while(k*k/3+4 < p || k%3) k++;
        if(k*k/3+4 == p){
            cout << t << " " << t - pre <<endl;
            pre =  t;
        }
    }
    return 0;
}
