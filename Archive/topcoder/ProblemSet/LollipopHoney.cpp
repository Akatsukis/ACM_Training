// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class LollipopHoney  
{  
    public:  
    const int mod = 1e9+7;
    vector <int> count(int K, vector <int> f, vector <int> d)
    {
        int n = f.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)), num(n+1, vector<int>(n+1, 0));
        for(int i = 0; i <= n; i++){
            num[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= K; j++) {
                for(int k = 1; k < i; k++){
                    if(f[i-1] != f[k-1]){
                        if(dp[i][j] < dp[k-1][j-1]+d[i-1]+d[k-1]){
                            dp[i][j] = dp[k-1][j-1]+d[i-1]+d[k-1];
                            if(n == 6)printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
                            num[i][j] = num[k-1][j-1];
                            //printf("num[%d][%d]=%d\n", i, j, num[i][j]);
                        }
                        else if(dp[i][j] == dp[k-1][j-1]+d[i-1]+d[k-1]){
                            num[i][j] = (num[i][j]+num[k-1][j-1])%mod;
                            //printf("num[%d][%d]=%d\n", i, j, num[i][j]);
                        }
                    }
                }
            }
        }
        if(dp[n][K] != 0)return{dp[n][K], num[n][K]};
        else return {};
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1 ; int Arr1[] = {1,1,2,2}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,20,30,40}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {60, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2 ; int Arr1[] = {1,1,1,2,2,2}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,20,20,20}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {60, 9 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2 ; int Arr1[] = {1,1,1,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,20,30,40,50,60}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3 ; int Arr1[] = {48,33,22,9,37,44,5,49,24,14,45,1}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,1,7,10,7,10,5,1,3,3,4,5}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {48, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10 ; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 846527861 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    LollipopHoney ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

