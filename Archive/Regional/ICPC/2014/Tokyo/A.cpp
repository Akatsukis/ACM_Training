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

const int maxn = 20;
int p[maxn], a[maxn], n, chs[maxn], m;

int check(int x)
{
    int cnt0 = 0, cnt1 = 0, need0 = 0, need1 = 1;
    for(int i = 0; i < m; i++){
        chs[i] = (i%2)?!x:x;
        if(chs[i]) need1 += p[i];
        else need0 += p[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i]) cnt1++;
        else cnt0++;
    }
    return need0 == cnt0;
}

int solve(int x)
{
    int tmp[maxn], res = 0, pos = 0;
    for(int i = 0; i < n; i++) tmp[i] = a[i];
    for(int i = 0; i < m; i++) chs[i] = (i%2)?!x:x;
    for(int i = 0, j = 0; i < m; i++){
        //printf("i:%d\n", i);
        while(j < pos+p[i]){
            int k;
            if(tmp[j] != chs[i]){
                for(k = j+1; k < n; k++) if(tmp[k] == chs[i]) break;
                for(int l = k-1; l >= j; l--) swap(tmp[l], tmp[l+1]), res++;
            }
            j++;
        }
        pos += p[i];
    }
    return res;
}
int main()
{
    while(sc(n) != EOF){
        sc(m);
        for(int i = 0; i < n; i++){
            sc(a[i]);
        }
        for(int i = 0; i < m; i++) sc(p[i]);
        int ans = 100;
        if(check(1)) ans = min(ans, solve(1));
        if(check(0)) ans = min(ans, solve(0));
        printf("%d\n", ans);
    }
    return 0;
}

