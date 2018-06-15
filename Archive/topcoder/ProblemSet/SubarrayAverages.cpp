// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int INF = 0x3f3f3f3f;
  
class SubarrayAverages  
{  
    public:  
    vector <double> findBest(vector <int> arr)  
    {  
        vector<double> ret;
        int n = arr.size();
        for(int i = 0; i < n;){
            int pos = 0, cnt = 0;
            double sum = 0, mn = INF;
            for(int j = i; j < n; j++){
                sum += arr[j];
                cnt++;
                if(sum/cnt < mn){
                    mn = sum/cnt;
                    pos = j;
                }
            }
            for(int j = i; j <= pos; j++)ret.pb(mn);
            i = pos+1;
        }   
        return ret;
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { int Arr0[] = {7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,1,2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1.0, 1.5, 1.5, 2.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findBest(Arg0)); }
	void test_case_3() { int Arr0[] = {1,10,1,1,1,1,10}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1.0, 2.8, 2.8, 2.8, 2.8, 2.8, 10.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findBest(Arg0)); }
	void test_case_4() { int Arr0[] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {4.0, 5.0, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846, 5.846153846153846 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findBest(Arg0)); }
	void test_case_5() { int Arr0[] = {1000000}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {1000000.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findBest(Arg0)); }
	void test_case_6() { int Arr0[] = {9450,7098,6048,1050,672,8232,5028,
672,672,42,42,42,42,42,9450,6048,
3402,3402,2688,9450,7098,6048,1050,
672,8232,5028,672,672,9450,6048,3402}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 2795.1428571428573, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 4565.142857142857, 6300.0, 6300.0, 6300.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, findBest(Arg0)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    SubarrayAverages ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
