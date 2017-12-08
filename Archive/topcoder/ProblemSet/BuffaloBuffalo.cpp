// BEGIN CUT HERE

// END CUT HERE
#line 5 "BuffaloBuffalo.cpp"
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
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
class BuffaloBuffalo
{
    public:
    string check(string s)
    {
    //$CARETPOSITION$
        int n = s.size();
        if(n % 8 != 7)return("Not good");
        for(int i = 0; i < n; i += 8){
            if(s.substr(i, 7) != "buffalo")return("Not good");
            if(i + 7 < n && s[i+7] != ' ')return("Not good");
        }
        return ("Good");
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "buffalo buffalo"; string Arg1 = "Good"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "buffalobuffalo"; string Arg1 = "Not good"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "buffalo buffalo buffalo"; string Arg1 = "Good"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "buf falo buffalo"; string Arg1 = "Not good"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { string Arg0 = "cow"; string Arg1 = "Not good"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { string Arg0 = "buffalo  buffalo"; string Arg1 = "Not good"; verify_case(5, Arg1, check(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BuffaloBuffalo test;
    test.run_test(-1);
}
// END CUT HERE
