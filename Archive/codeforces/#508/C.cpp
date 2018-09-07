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
priority_queue<int> qa, qb;

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int x; sc(x);
        qa.push(x);
    }
    for(int i = 0; i < n; i++){
        int x; sc(x);
        qb.push(x);
    }
    ll a = 0, b = 0;
    int cur = 0;
    while(qa.size() || qb.size()){
        if(!cur){
            if(qa.empty())qb.pop();
            else if(qb.empty())a += qa.top(), qa.pop();
            else{
                int u = qa.top(), v = qb.top();
                if(u > v)a += u, qa.pop();
                else qb.pop();
            }
        }
        else{
            if(qa.empty())b += qb.top(), qb.pop();
            else if(qb.empty())qa.pop();
            else{
                int u = qa.top(), v = qb.top();
                if(v > u)b += v, qb.pop();
                else qa.pop();
            }
        }
        //printf("a=%lld, b=%lld\n", a, b);
        cur ^= 1;
    }
    printf("%lld\n", a-b);
    return 0;
}

