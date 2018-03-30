// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
  
class TileFlippingGame  
{  
    public:
    vector<int> s[60];
    bool vis[60][60];
    int dep[60][60];
    int n_, m_, mx;
    void dfs(int x, int y)
    {
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx >= 0 && nx < n_ && ny >= 0 && ny < m_ && s[nx][ny] != 0 && !vis[nx][ny]){
                if(s[nx][ny] != s[x][y])dep[nx][ny] = dep[x][y]+1;
                else dep[nx][ny] = dep[x][y];
                mx = max(mx, dep[nx][ny]);
                dfs(nx, ny);
            }
        }
    }
    int HowManyMoves(int n, int m, vector <string> X)  
    {
        n_ = n, m_ = m;
        for(int i = 0; i <= n; i++)s[i].clear();
        memset(dep, 0, sizeof(dep));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(X[i][j] == 'w')s[i].pb(1);
                else if(X[i][j] == 'e')s[i].pb(0);
                else s[i].pb(-1);
            }
        }
        vector<int> res[2];
        res[0].clear(), res[1].clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(!s[i][j])continue;
                    mx = 0;
                    dep[i][j] = 1;
                    dfs(i, j);
                    if(mx%2==0){
                        res[0].pb(mx/2);
                        res[1].pb(mx/2);
                    }
                    else{
                        if(s[i][j] == 1){
                            res[0].pb(mx/2+1);
                            res[1].pb(mx/2);
                        }
                        else{
                            res[0].pb(mx/2);
                            res[1].pb(mx/2+1);
                        }   
                    }
                }
            }
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < (int)res[0].size(); i++){
            ans1 += res[0][i], ans2 += res[1][i];
        }
        return max(ans1, ans2);
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"bbb","eee","www"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"bwe","wbw","ewb"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"beww","beww","beww","wewe"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(2, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 8; string Arr2[] = {"ewewbbbb","bwebewww"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; string Arr2[] = {"bwebw","wbebb","eeeee","bbebb","bbebb"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 6; int Arg1 = 7; string Arr2[] = {"bwbbbbb","bwbwwwb","bwbwewb","bwbbbwb","bwwwwwb","bbbbbbb"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(5, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 6; int Arg1 = 7; string Arr2[] = {"bwbbbbb","bwbwwwb","eeeeeee","bwbbbwb","bwwwwwb","bbbbbbb"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(6, Arg3, HowManyMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    TileFlippingGame ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
