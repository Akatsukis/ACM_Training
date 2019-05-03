// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class EllysTeleport  
{  
    public:  
    int getMax(int n, int H0, int A, int B, int P, int Q, int M)  
    {
        vector<int> h(n, 0), nxt(n, 0);
        h[0] = H0;
        for(int i = 1; i < n; i++)h[i] = (1LL*h[i-1]*A+B)%M;
        sort(h.begin(), h.end());
        for(int i = 0; i < n; i++){
            int y = (1LL*h[i]*P+Q)%M;
            int pos = upper_bound(h.begin(), h.end(), y)-h.begin()-1;
            nxt[i] = pos;
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            vector<bool> vis(n, 0);
            vis[i] = 1;
            int cur = i, tot = 1;
            while(nxt[cur] != -1 && !vis[nxt[cur]]){
                cur = nxt[cur];
                vis[cur] = 1;
                tot++;
            }
            ans = max(ans, tot);
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 9; int Arg2 = 17; int Arg3 = 9; int Arg4 = 7; int Arg5 = 13; int Arg6 = 23; int Arg7 = 6; verify_case(0, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 17; int Arg2 = 23; int Arg3 = 19; int Arg4 = 15; int Arg5 = 28; int Arg6 = 43; int Arg7 = 4; verify_case(1, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 42; int Arg2 = 114; int Arg3 = 52; int Arg4 = 76; int Arg5 = 1; int Arg6 = 131; int Arg7 = 5; verify_case(2, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 71; int Arg2 = 54; int Arg3 = 85; int Arg4 = 96; int Arg5 = 52; int Arg6 = 100; int Arg7 = 10; verify_case(3, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 1337; int Arg2 = 706135; int Arg3 = 1085680; int Arg4 = 1153206; int Arg5 = 345473; int Arg6 = 1234567; int Arg7 = 42; verify_case(4, Arg7, getMax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    EllysTeleport ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

