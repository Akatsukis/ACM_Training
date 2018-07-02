// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromeSubsequence.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(), x.end()
class PalindromeSubsequence
{
    public:
    vector <int> optimalPartition(string s)
    {
    //$CARETPOSITION$
        string t = s;
        reverse(ALL(t));
        if(t == s){
            vector<int> ret;
            int n = s.size();
            for(int i = 0; i < n; i++){
                ret.pb(1);
            }
            return ret;
        }
        else{
            vector<int> ret;
            int n = s.size();
            for(int i = 0; i < n; i++){
                if(s[i] == 'a')ret.pb(1);
                else ret.pb(2);
            }
            return ret;
        }
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "bababba"; int Arr1[] = {1, 2, 2, 1, 2, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, optimalPartition(Arg0)); }
	void test_case_1() { string Arg0 = "abba"; int Arr1[] = {1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, optimalPartition(Arg0)); }
	void test_case_2() { string Arg0 = "b"; int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, optimalPartition(Arg0)); }
	void test_case_3() { string Arg0 = "babb"; int Arr1[] = {1, 1, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, optimalPartition(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PalindromeSubsequence test;
    test.run_test(-1);
}
// END CUT HERE
