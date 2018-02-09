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
string s, t;
int n;
map<string, int> mp;

int bfs()
{
    queue<string> q;
    mp[s] = 0;
    q.push(s);
    while(q.size()){
        string now = q.front();q.pop();
        //cout <<">>>"<<now <<endl;
        if(now == t)return mp[now];
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string tmp = now;
                swap(tmp[i], tmp[j]);
                //cout << tmp << endl;
                if(!mp.count(tmp) || mp[tmp] > mp[now]+1){
                    mp[tmp] = mp[now]+1;
                    q.push(tmp);
                }
            }
        }
        for(int i = 0; i < n; i++){
            string tmp = now;
            int cnt = i;
            while(cnt != -1 && tmp[cnt] == '9'){
                tmp[cnt] = '0';
                cnt--;
            }
            if(cnt != -1){
                tmp[cnt]++;
                if(!mp.count(tmp) || mp[tmp] > mp[now]+1){
                    mp[tmp] = mp[now]+1;
                    q.push(tmp);
                }
            }
            tmp = now;
            cnt = i;
            while(cnt != -1 && tmp[cnt] == '0'){
                tmp[cnt] = '9';
                cnt--;
            }
            if(cnt != -1){
                tmp[cnt]--;
                //cout << tmp << endl;
                if(!mp.count(tmp) || mp[tmp] > mp[now]+1){
                    mp[tmp] = mp[now]+1;
                    q.push(tmp);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> s >> t;
    int ans = bfs();
    printf("%d\n", ans);
    return 0;
}

