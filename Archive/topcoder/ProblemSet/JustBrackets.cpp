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
  
class JustBrackets  
{  
    public:  
    string getSmallest(string s)  
    {  
            
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()"; string Arg1 = "()"; verify_case(0, Arg1, getSmallest(Arg0)); }
	void test_case_1() { string Arg0 = "()()"; string Arg1 = "()"; verify_case(1, Arg1, getSmallest(Arg0)); }
	void test_case_2() { string Arg0 = "(())"; string Arg1 = "(())"; verify_case(2, Arg1, getSmallest(Arg0)); }
	void test_case_3() { string Arg0 = "(()(()))"; string Arg1 = "((()))"; verify_case(3, Arg1, getSmallest(Arg0)); }
	void test_case_4() { string Arg0 = "((())()(()(())(())))"; string Arg1 = "(((())(())))"; verify_case(4, Arg1, getSmallest(Arg0)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    JustBrackets ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
