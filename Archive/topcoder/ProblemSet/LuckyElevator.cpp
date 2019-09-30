// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class LuckyElevator  
{  
    public:  
    bool check(int num) {
        while(num) {
            if(num%10 == 4)return 0;
            num /= 10;
        }
        return 1;
    }
    int actualFloor(int buttonPressed)  
    {
        int ans = 0;
        for(int i = 1; i <= buttonPressed; i++) {
            if(check(i))ans++;
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; verify_case(0, Arg1, actualFloor(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; verify_case(1, Arg1, actualFloor(Arg0)); }
	void test_case_2() { int Arg0 = 18; int Arg1 = 16; verify_case(2, Arg1, actualFloor(Arg0)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 36; verify_case(3, Arg1, actualFloor(Arg0)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 59049; verify_case(4, Arg1, actualFloor(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    LuckyElevator ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

