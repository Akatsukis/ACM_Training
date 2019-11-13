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
const int HALF = 15;

void norm(vector<int> &vec) {
    for(int i = (int)vec.size()-1; i >= 0; i--) {
        vec[i] -= vec[0];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    map<vector<int>, int> mp;
    for(int mask = 0; mask < 1<<HALF; mask++) {
        vector<int> cnt(n);
        for(int i = 0; i < n; i++) {
            int v = vec[i]&((1<<HALF)-1);
            v ^= mask;
            cnt[i] = __builtin_popcount(v);
        }
        norm(cnt);
        if(mp.find(cnt) == mp.end()) {
            mp[cnt] = mask;
        }
    }
    int ans = -1;
    for(int mask = 0; mask < 1<<HALF; mask++) {
        vector<int> cnt(n);
        for(int i = 0; i < n; i++) {
            int v = vec[i]>>HALF;
            v ^= mask;
            cnt[i] = __builtin_popcount(v);
        }
        norm(cnt);
        for(auto &u: cnt) {
            u = -u;
        }
        if(mp.find(cnt) != mp.end()) {
            ans = (mask<<HALF)+mp[cnt];
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

