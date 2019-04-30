// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
#define fi first
#define se second
  
class CentipedeSocks  
{  
    public:  
    int fewestSocks(int C, int F, vector <int> sockCounts)  
    {
        if(sockCounts.size() == 1){
            if(sockCounts[0] < C*F)return -1;
            else return C*F;
        }
        priority_queue<pii> pq;
        for(int i = 0; i < (int)sockCounts.size(); i++){
            pq.push(mk(sockCounts[i], i));
        }
        int ans = 0;
        while(C > 1){
            pii p = pq.top(); pq.pop();
            if(sockCounts[p.se] < F)return -1;
            sockCounts[p.se] -= F;
            ans += F;
            C--;
            pq.push(mk(sockCounts[p.se], p.se));
        }
        bool ok = 0;
        for(int i = 0; i < (int)sockCounts.size(); i++){
            if(sockCounts[i] >= F)ok = 1;
            ans += min(F-1, sockCounts[i]);
        }
        if(ok)return ans+1;
        else return -1;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 100; int Arr2[] = {1, 1, 1, 1, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 104; verify_case(0, Arg3, fewestSocks(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arr2[] = {40, 50, 60, 70}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, fewestSocks(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 10; int Arr2[] = {12345}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 30; verify_case(2, Arg3, fewestSocks(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {4, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, fewestSocks(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    CentipedeSocks ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

