// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
class OneHandRoadPainting  
{  
    public:  
    long long fastest(vector <int> dStart, vector <int> dEnd, int paintPerBrush)  
    {  
        int n = dStart.size();
        ll ans = 0, lft = 0;
        for(int i = n-1; i >= 0; i--){
            ll st = dStart[i], ed = dEnd[i];
            if(lft >= ed-st){
                lft -= ed-st;
                continue;
            }
            ed -= lft; lft = 0;
            ll num = (ed-st+paintPerBrush-1)/paintPerBrush;
            ll fr = ed, to = fr-(num-1)*paintPerBrush;
            ans += (fr+to)*num;
            lft = st-(to-paintPerBrush);
        }
        return ans;
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; long long Arg3 = 42LL; verify_case(0, Arg3, fastest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; long long Arg3 = 18LL; verify_case(1, Arg3, fastest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 13, 22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 98LL; verify_case(2, Arg3, fastest(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    OneHandRoadPainting ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
