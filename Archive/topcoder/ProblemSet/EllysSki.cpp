// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class EllysSki  
{  
    public:  
    int getMax(vector <int> height)  
    {
        int n = height.size();
        int cur = 1, ans = 1;
        for(int i = 1; i < n; i++){
            if(height[i] >= height[i-1])cur++, ans = max(cur, ans);
            else cur = 1;
        }
        cur = 1;
        for(int i = n-2; i >= 0; i--){
            if(height[i] >= height[i+1])cur++, ans = max(cur, ans);
            else cur = 1;
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { int Arr0[] = {42, 42, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { int Arr0[] = {543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955, 66, 573, 982, 296, 730, 591}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { int Arr0[] = {50, 77, 24, 86, 98, 84, 42, 70, 88, 78, 73, 17, 76, 68, 64, 65, 40, 77, 33, 87, 11, 23, 78, 20, 8, 74, 44, 95, 94, 78, 27, 88, 71, 40, 11, 98, 82, 85, 79, 89, 31, 67, 41, 61, 71, 62, 74, 77, 86, 36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, getMax(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    EllysSki ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

