// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;

long long pos(long long a, long long b) {
    return abs(a-b);
}
  
class TwoLadders  
{  
    public:  
    long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y)  
    {
        vector<pair<int, int> > vec;
        int n = X.size();
        for(int i = 0; i < n; i++) {
            vec.push_back(make_pair(Y[i], X[i]));
        }
        sort(vec.begin(), vec.end());
        int prey = 0;
        long long dp[2][2] = {};
        int cur = 0, nxt = 1;
        for(int i = 0; i < n;) {
            memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
            int j = 1;
            while(i+j < n && vec[i+j].first == vec[i].first) j++;
            int l = vec[i].second, r = vec[i+j-1].second;
            int lm1 = min(lx1, l), rm1 = max(lx1, r);
            int lm2 = min(lx2, l), rm2 = max(lx2, r);
            if(i == 0) {
                if(vec[i].first != 0) {
                    dp[cur][0] = pos(sx, lx1); 
                    dp[cur][1] = pos(sx, lx2);
                }
                else {
                    lm1 = min(sx, l), rm1 = max(sx, r);
                    lm2 = min(sx, l), rm2 = max(sx, r);
                }
            }
            if(i+j == n) {
                if(r <= lx1) {
                   dp[nxt][0] = vec[i].first+prey+
                }
            }
            dp[nxt][0] = vec[i].first-prey+min(dp[cur][0]+pos(lx1, lm1)+pos(lm1, rm1)+pos(rm1, lx1), dp[cur][1]+pos(lx2, rm2)+pos(rm2, lm1)+pos(lm1, lx1));
            dp[nxt][1] = vec[i].first-prey+min(dp[cur][0]+pos(lx1, lm1)+pos(lm1, rm2)+pos(rm2, lx2), dp[cur][1]+pos(lx2, rm2)+pos(rm2, lm2)+pos(lm2, lx2));
            prey = vec[i].first;
            i += j;
            swap(cur, nxt);
        }
        return min(dp[cur][0], dp[cur][1]);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 100; int Arr3[] = {47, 42}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 37LL; verify_case(0, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 11; int Arr3[] = {10, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 5LL; verify_case(1, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 42; int Arr3[] = {10, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 7LL; verify_case(2, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 42; int Arr3[] = {10, 100, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 0, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 181LL; verify_case(3, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 500000000; int Arg1 = 1; int Arg2 = 999999999; int Arr3[] = {0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 999999947, 999999947, 900000047, 900000047}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 8499999959LL; verify_case(4, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    TwoLadders ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

