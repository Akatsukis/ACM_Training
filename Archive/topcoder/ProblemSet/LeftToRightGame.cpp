// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class LeftToRightGame  
{  
    public:  
    string whoWins(int length, int divisor)  
    {  
        if(length%2 == 1){
            if(divisor == 1)return "Bob";
            else return "Alice";
        }
        else{
            if(divisor >= 1 && divisor <= 10)return "Bob";
            else if(divisor == 11 && length == 2)return "Bob";
            else return "Alice";
        }
    } 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 10; string Arg2 = "Bob"; verify_case(0, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1000; string Arg2 = "Alice"; verify_case(1, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "Bob"; verify_case(2, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 147; int Arg1 = 47; string Arg2 = "Alice"; verify_case(3, Arg2, whoWins(Arg0, Arg1)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    LeftToRightGame ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
