// BEGIN CUT HERE

// END CUT HERE
#line 5 "MajoritySubarray.cpp"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
class MajoritySubarray
{
    public:
    long long getCount(int n, int seed, int m)
    {
        ll u = seed, mod = m;
        vector<ll> vec;
        for(int i = 0; i < n; i++){
            vec.pb(u/(1LL<<16)%mod);
            //printf("u=%lld\n", u/(1LL<<16)%mod);
            u = (u*1103515245+12345)%(1LL<<31);
        }

    //$CARETPOSITION$
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 200; int Arg2 = 5; long long Arg3 = 8LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 3; long long Arg3 = 23LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 12345678; int Arg2 = 1; long long Arg3 = 36LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 27; int Arg1 = 541; int Arg2 = 50; long long Arg3 = 27LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MajoritySubarray test;
    test.run_test(-1);
}
// END CUT HERE
