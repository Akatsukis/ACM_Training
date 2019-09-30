// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class TheUnexpectedSwap  
{  
    public:  
    const int mod = 1e9+7;
    int findExpectedResult(int n, string s, int seed)  
    {
        vector<int> A(n, 0);
        vector<int> pw(n, 0);
        pw[0] = 1;
        for(int i = 1; i < n; i++) {
            pw[i] = pw[i-1]*10LL%mod;
        }
        A[0] = seed;
        for(int i = 1; i < n; i++) {
            A[i] = (A[i-1]*1009LL+10009)%100019;
        }
        for(int i = (int)s.size(); i < n; i++) {
            char c = s[A[i]%i];
            s.push_back(c);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += s[i]-'0';
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long cur = 0;
            cur += (sum-(s[i]-'0'))*2;
            cur += 1LL*(n-1)*(n-2)*(s[i]-'0');
            cur = cur%mod*pw[n-1-i]%mod;
            ans = (ans+cur)%mod;
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 = "32"; int Arg2 = 0; int Arg3 = 46; verify_case(0, Arg3, findExpectedResult(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "60"; int Arg2 = 0; int Arg3 = 12; verify_case(1, Arg3, findExpectedResult(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arg1 = "1"; int Arg2 = 0; int Arg3 = 999999297; verify_case(2, Arg3, findExpectedResult(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; string Arg1 = "123"; int Arg2 = 47; int Arg3 = 5331084; verify_case(3, Arg3, findExpectedResult(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    TheUnexpectedSwap ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

