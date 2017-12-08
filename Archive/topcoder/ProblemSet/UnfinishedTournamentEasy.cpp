// BEGIN CUT HERE

// END CUT HERE
#line 5 "UnfinishedTournamentEasy.cpp"
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
const int INF = 2e9+5;
const int maxn = 30;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
class UnfinishedTournamentEasy
{
    public:
    double maximal(vector <string> G)
    {
    //$CARETPOSITION$
        bool del[maxn];
        memset(del, 0, sizeof(del));
        int n = (int)G.size();
        for(int i = 0; i < n; i++){
            int nowwin = 0, pos = -1, nowlose = INF;
            for(int j = 0; j < n; j++){
                if(del[j])continue;
                if(pos == -1)pos = j;
                int win = 0, lose = 0;
                for(int k = 0; k < n; k++){
                    if(G[j][k] == 'W' || G[j][k] == '?')win++;
                    if(G[j][k] == 'L')lose++;
                }
                if(win > nowwin || (win == nowwin || lose < nowlose)){
                    nowwin = win;
                    nowlose = lose;
                    pos = j;
                }
            }
            del[pos] = 1;
            //pr(pos);
            for(int k = 0; k < n; k++){
                if(G[pos][k] == '?'){
                    G[pos][k] = 'W';
                    G[k][pos] = 'L';
                }
            }
        }
        double ans[maxn], sum = 0, avg = 0;
        for(int i = 0; i < n; i++){
            double now = 0;
            for(int j = 0; j < n; j++){
                if(G[i][j] == 'W')now++;
            }
            ans[i] = now / (n-1);
            //printf("ans[%d]:%.5f\n", i, ans[i]);
            sum += ans[i];
        }
        avg = sum / n;
        double res = 0;
        for(int i = 0; i < n; i++){
            res += (ans[i]-avg)*(ans[i]-avg);
        }
        res /= n;
        return res;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-??",
 "?-?",
 "??-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.16666666666666669; verify_case(0, Arg1, maximal(Arg0)); }
	void test_case_1() { string Arr0[] = {"-WL",
 "L-W",
 "WL-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, maximal(Arg0)); }
	void test_case_2() { string Arr0[] = {"-WWL",
 "L-??",
 "L?-?",
 "W??-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1388888888888889; verify_case(2, Arg1, maximal(Arg0)); }
	void test_case_3() { string Arr0[] = {"-WWL",
 "L-WW",
 "LL-?",
 "WL?-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.08333333333333331; verify_case(3, Arg1, maximal(Arg0)); }
	void test_case_4() { string Arr0[] = {"-?",
 "?-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.25; verify_case(4, Arg1, maximal(Arg0)); }
	void test_case_5() { string Arr0[] = {"-WWL?",
"L-L??",
"LW-?W",
"W??-L",
"??LW-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.07500000000000001; verify_case(5, Arg1, maximal(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    UnfinishedTournamentEasy test;
    test.run_test(-1);
}
// END CUT HERE
