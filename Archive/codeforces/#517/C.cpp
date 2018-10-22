#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
vector<int> vec, vec1;
set<int> st;

int main()
{
    int a, b;
    sc(a); sc(b);
    int num = 1;
    while(a >= num){
        vec.pb(num);
        a -= num;
        num++;
    }
    for(int j = SZ(vec)-1; a; a--, j--)vec[j]++;
    for(auto u : vec)st.insert(u);
    for(int i = 1; ; i++){
        if(b < i)break;
        if(st.count(i))continue;
        b -= i;
        vec1.pb(i);
    }
    printf("%d\n", SZ(vec));
    for(int i = 0; i < SZ(vec); i++)printf("%d%c", vec[i], " \n"[i==SZ(vec)-1]);
    printf("%d\n", SZ(vec1));
    for(int i = 0; i < SZ(vec1); i++)printf("%d%c", vec1[i], " \n"[i==SZ(vec1)-1]);
    return 0;
}

