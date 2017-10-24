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
const int maxn = 1e5 + 10;
int a[maxn];
int n;
int del;

bool check()
{
    int now;
    if(del != 1)now = a[1];
    else now = a[2];
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(del == i)continue;
        if(a[i] < now){
            flag = 0;
            break;
        }
        else now = a[i];
    }
    if(flag)return 1;
    else flag = 1;
    if(del != 1)now = a[1];
    else now = a[2];
    for(int i = 1; i <= n; i++){
        if(del == i)continue;
        if(a[i] > now){
            flag = 0;
            break;
        }
        else now = a[i];
    }
    if(flag)return 1;
    else return 0;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        del = 0;
        sc(n);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
        }
        if(check()){
            printf("YES\n");
            continue;
        }
        bool fst = 0;
        bool flag = 0;
        for(int i = 2; i <= n; i++){
            if(!fst && a[i] > a[i - 1]){
                del = i - 1;
                if(check()){
                    printf("YES\n");
                    flag = 1;
                    break;
                }
                del = i;
                if(check()){
                    printf("YES\n");
                    flag = 1;
                    break;
                }
                del = 0;
                fst = 1;
            }
            else if(fst && a[i] > a[i - 1]){
                break;
            }
        }
        if(flag)continue;
        fst = 0;
        for(int i = 2; i <= n; i++){
            if(!fst && a[i] < a[i - 1]){
                del = i - 1;
                if(check()){
                    printf("YES\n");
                    flag = 1;
                    break;
                }
                del = i;
                if(check()){
                    printf("YES\n");
                    flag = 1;
                    break;
                }
                del = 0;
                fst = 1;
            }
            else if(fst && a[i] < a[i - 1]){
                break;
            }
        }
        if(flag)continue;
        else printf("NO\n");
    }
	return 0;
}


