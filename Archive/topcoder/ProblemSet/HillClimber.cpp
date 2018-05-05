// BEGIN CUT HERE

// END CUT HERE
#line 5 "HillClimber.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
class HillClimber {
    public:
    int longest(vector <int> height) {
        int cnt = 0, ans = 0;
        int n = (int)height.size();
        for(int i = 1; i < n; i++){
            if(height[i] > height[i-1]){
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                cnt = 0;
            }
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 3, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, longest(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2, 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, longest(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 8, 9, 12 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, longest(Arg0)); }
	void test_case_3() { int Arr0[] = { 10, 4, 4, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, longest(Arg0)); }
	void test_case_4() { int Arr0[] = { 10, 8, 4, 9, 11, 14, 15, 3, 7, 8, 10, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, longest(Arg0)); }

// END CUT HERE
  
};
// BEGIN CUT HERE  
int main()  
{  
    HillClimber ___test;  
     ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
