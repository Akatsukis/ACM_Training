// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class DivisorSequences  
{  
    public:
    unordered_map<int, int> mp;
    int get(int n) {
        if(n <= 1)return 0;
        if(mp.count(n))return mp[n];
        else mp[n] = 1;
        for(int i = 2; i*i <= n; i++) {
            if(n%i == 0) {
                mp[n] = max(mp[n], get(n/i-1)+1);
                mp[n] = max(mp[n], get(i-1)+1);
            }
        }
        return mp[n];
    }
    int longest(int N)  
    {
        int ans = 0;
        for(int i = 1; i*i <= N; i++) {
            if(N%i == 0) {
                ans = max(ans, get(N/i-1)+1);
                ans = max(ans, get(i-1)+1);
            }
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; verify_case(0, Arg1, longest(Arg0)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 2; verify_case(1, Arg1, longest(Arg0)); }
	void test_case_2() { int Arg0 = 34; int Arg1 = 4; verify_case(2, Arg1, longest(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    DivisorSequences ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

