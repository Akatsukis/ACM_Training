// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class EllysPearls  
{  
    public:  
    int getMin(int n, int m, vector <int> col)
    {
        vector<vector<int> > dp(1<<m, vector<int>(n, 0));
        for(auto &u: col)u--;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int mask = 0; mask < (1<<m); mask++){
                if(!(mask>>col[i]&1))continue;
                else dp[mask][i] = max(dp[mask][i], 1);
                for(int j = 0; j < i; j++){
                    if(col[i] == col[j])dp[mask][i] = max(dp[mask][i], dp[mask][j]+1);
                    else dp[mask][i] = max(dp[mask][i], dp[mask^(1<<col[i])][j]+1);
                }
                ans = max(ans, dp[mask][i]);
            }
        }
        return n-ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 4; int Arr2[] = {2, 4, 1, 1, 1, 3, 2, 1, 4, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arr2[] = {2, 2, 2, 1, 2, 2, 2, 1, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 7; int Arr2[] = {5, 6, 2, 4, 7, 2, 2, 3, 3, 6, 1, 3, 6, 3, 7, 5, 1, 2, 3, 4, 6, 5, 6, 3, 2, 5, 3, 3, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(3, Arg3, getMin(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    EllysPearls ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

