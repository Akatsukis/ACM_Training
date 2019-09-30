// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class SaturdayNightStay  
{  
    public:  
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countOptions(int firstDay, int firstMonth, int lastDay, int lastMonth)  
    {
        int curM = 1, curD = 1, week = 2;
        while(curM < firstMonth) {
            week = (week+day[curM])%7;
            curM++;
        }
        week = (week+firstDay-curD)%7;
        curD = firstDay;
        int pre = 0, tot = 0, ans = 0;
        while(1) {
            if(week == 0) {
                tot += pre;
                pre = 0;
            }
            ans += tot;
            pre++;
            if(curM == lastMonth && curD == lastDay)break;
            if(curD == day[curM]) {
                curD = 1;
                curM++;
            }
            else curD++;
            week = (week+1)%7;
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arg1 = 6; int Arg2 = 16; int Arg3 = 6; int Arg4 = 1; verify_case(0, Arg4, countOptions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 16; int Arg1 = 6; int Arg2 = 22; int Arg3 = 6; int Arg4 = 0; verify_case(1, Arg4, countOptions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 31; int Arg3 = 1; int Arg4 = 382; verify_case(2, Arg4, countOptions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 19; int Arg3 = 10; int Arg4 = 2485; verify_case(3, Arg4, countOptions(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    SaturdayNightStay ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

