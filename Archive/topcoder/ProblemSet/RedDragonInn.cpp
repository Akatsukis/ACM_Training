// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class RedDragonInn  
{  
    public:  
    int maxGold(int N, int X)  
    {  
        return (X*N+N-1)*2+1; 
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 17; verify_case(0, Arg2, maxGold(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 13; int Arg2 = 223; verify_case(1, Arg2, maxGold(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 42; int Arg1 = 1234; int Arg2 = 103739; verify_case(2, Arg2, maxGold(Arg0, Arg1)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    RedDragonInn ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
