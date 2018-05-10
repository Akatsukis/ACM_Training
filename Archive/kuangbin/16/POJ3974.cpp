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
const int maxn = 2e6+10;
char s[maxn], t[maxn];
int ma[maxn];

int manacher()
{
    t[0] = '$', t[1] = '#';
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        t[i*2+2] = s[i];
        t[i*2+3] = '#';
    }
    int mx = -1, ctr = -1, ret = 1;
    for(int i = 1; i < n*2+2; i++){
        if(i < mx)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(t[i-ma[i]] == t[i+ma[i]])ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
        ret = max(ret, ma[i]-1);
    }
    return ret;
}

int main()
{
    int kase = 1;
    while(scanf("%s", s) != EOF){
        if(!strcmp(s, "END"))break;
        int ans = manacher();
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}

