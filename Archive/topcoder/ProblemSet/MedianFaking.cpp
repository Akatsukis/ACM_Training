// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class MedianFaking  
{  
    public:  
    vector <int> minimize(int F, int M, vector <int> data, int goal)  
    {
        int n = F*M;
        vector<int> vec = data;
        sort(vec.begin(), vec.end());
        int cur = vec[(n-1)/2];
        if(cur == goal) {
            return {0, 0};
        }
        else if(cur > goal) {
            int need = 0;
            for(auto u: vec) {
                if(u > goal)need++;
            }
            need -= n/2;
            priority_queue<int> pq;
            for(int i = 0; i < F; i++) {
                int num = 0;
                for(int j = 0; j < M; j++) {
                    int sc = data[i*M+j];
                    if(sc > goal) {
                        num++;
                    }
                }
                pq.push(num);
            }
            int ans1 = 0, ans2 = 0;
            while(need > 0) {
                int num = pq.top(); pq.pop();
                ans1++; ans2 += min(need, num);
                need -= num;
            }
            return {ans1, ans2};
        }
        else {
            int need = 0;
            for(auto u: vec) {
                if(u < goal)need++;
            }
            need -= (n-1)/2;
            priority_queue<int> pq;
            for(int i = 0; i < F; i++) {
                int num = 0;
                for(int j = 0; j < M; j++) {
                    int sc = data[i*M+j];
                    if(sc < goal) {
                        num++;
                    }
                }
                pq.push(num);
            }
            int ans1 = 0, ans2 = 0;
            while(need > 0) {
                int num = pq.top(); pq.pop();
                ans1++; ans2 += min(need, num);
                need -= num;
            }
            return {ans1, ans2};
        }
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arr4[] = {1, 5 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arr4[] = {2, 5 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 4; int Arr2[] = {10, 40, 30, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; int Arr4[] = {0, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arr2[] = {3,8,12, 3,8,12, 3,8,12, 8,12,17}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; int Arr4[] = {1, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {10, 20, 30, 40, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; int Arr4[] = {1, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    MedianFaking ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

