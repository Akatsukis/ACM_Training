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
#define freout freopen("out.txt","w",stdout)
#define debug cout<<"???"<<endl
#define PI 3.14159265358979323846

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e5;
char s[maxn];
int deg[maxn];
string ans;
bool vis[maxn];
int n;
struct Node
{
    int deg, val, id;
}p[maxn];
bool cmp(Node a, Node b)
{
    if(a.val != b.val)return a.val > b.val;
    return a.deg < b.deg;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(deg, 0, sizeof(deg));
        memset(vis, 0, sizeof(vis));
        sc(n);
        scanf("%s", s);
        for(int i = 0; i < n; i++){
            p[i].val = s[i] - '0', p[i].deg = deg[i], p[i].id = i;
        }
        ans.clear();
        for(int i = 0; i < n; i++){
            ans.pb('0');
        }
        sort(p, p + n, cmp);
        for(int i = 0; i < n; i++){
            int now = p[i].id;
            bool flag = 0;
            for(int j = 0; j < n; j++){
                if(s[now] > ans[j]){
                    flag = 1;
                }
                else if(s[now] == ans[j]){
                    if(vis[now] && flag == 0)break;
                }
                else if(s[now] < ans[j]){
                    if(flag == 0){
                        vis[now] = 1;
                        break;
                    }
                }
                vis[now] = 1;
                if(flag)ans[j] = s[now];
                now = (ll)(now*now+1)%n;
            }
            //cout << p[i].id << endl;
            //cout << ans << endl;
        }
        cout << "Case #" << kase++ << ": " << ans << endl;
    }
    return 0;
}

