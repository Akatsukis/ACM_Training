#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
vector<int> l, r;
string s, t;
int del[2000];

void solve(int x)
{
    int now = 1;
    for(int i = x+1; i < (int)s.size(); i++){
        if(s[i] == '(' && !del[i]){
            del[i] = 1;
            now++;
            solve(i);
        }
        if(s[i] == ')')now--;
        if(!now){
            reverse(t.begin()+x+1, t.begin()+i);
            break;
        }
    }
}

int main()
{
    cin >> s;
    t = s;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '(' && !del[i]){
            solve(i);
        }
    }
    for(int i = 0; i < (int)t.size(); i++){
        if(t[i] != '(' && t[i] != ')')printf("%c", t[i]);
    }
    printf("\n");
    return 0;
}

