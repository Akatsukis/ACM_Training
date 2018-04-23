// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(A) A.begin(), A.end()
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
  
class Deadfish  
{  
    public:
    int maxn = 1e6+10;
    int cost[1000010];
    int shortestCode(int _N)  
    {  
        for(int i = 0; i < maxn; i++)cost[i] = INF;
        cost[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == _N)return cost[u];
            if(u+1 < maxn && cost[u+1] == INF){
                cost[u+1] = cost[u]+1;
                q.push(u+1);
            }
            if(u-1 >= 0 && cost[u-1] == INF){
                cost[u-1] = cost[u]+1;
                q.push(u-1);
            }
            if((ll)u*u < maxn && cost[u*u] == INF){
                cost[u*u] = cost[u]+1;
                q.push(u*u);
            }
            string s = to_string(u);
            sort(ALL(s), greater<int>());
            int now = stoi(s);
            if(now >= 0 && now < maxn && cost[now] == INF){
                cost[now] = cost[u]+1;
                q.push(now);
            }
        }
        return cost[_N];
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; verify_case(0, Arg1, shortestCode(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; verify_case(1, Arg1, shortestCode(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 5; verify_case(2, Arg1, shortestCode(Arg0)); }
	void test_case_3() { int Arg0 = 61; int Arg1 = 5; verify_case(3, Arg1, shortestCode(Arg0)); }
	void test_case_4() { int Arg0 = 200000; int Arg1 = 207; verify_case(4, Arg1, shortestCode(Arg0)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    Deadfish ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
