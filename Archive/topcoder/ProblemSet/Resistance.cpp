// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
  
class Resistance  
{  
    public:
    vector<int> tmp;
    int P, S;
    vector<string> missions;
    vector<vector<int> > ans;
    void solve()
    {
        set<int> st;
        bool flg = 1;
        for(auto u : tmp)st.insert(u);
        for(int i = 0; i < (int)missions.size(); i++){
            if(missions[i][0] == 'S')continue;
            bool now = 0;
            for(int j = 1; j <= P; j++){
                if(missions[i][j] == '1' && st.count(j)){
                    now = 1;
                    break;
                }   
            }
            if(!now){
                flg = 0;
                break;
            }
        }
        if(flg){
            ans.pb(tmp);
        }
    }
    void dfs(int k, int now)
    {
        if(now == S){
            solve();
            return;
        }
        for(int i = k; i <= P; i++){
            tmp.pb(i);
            dfs(i+1, now+1);
            tmp.pop_back();
        }
    }
    vector <double> spyProbability(int _P, int _S, vector <string> _missions)  
    {  
        P = _P, S = _S, missions = _missions;
        ans.clear();
        dfs(1, 0);
        if(!ans.size())return vector<double>{};
        else{
            vector<double> ret(P);
            for(auto &u : ret)u = 0;
            for(auto vec : ans){
                for(int u : vec){
                    ret[u-1] += 1.0/ans.size();
                }
            }
            return ret;
        }
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; string Arr2[] = {"S0110",
 "F1100",
 "S0011"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.5, 0.5, 0.0, 0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, spyProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; string Arr2[] = {"F0100",
 "S0101",
 "F1010",
 "S1011"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.5, 1.0, 0.5, 0.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, spyProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; string Arr2[] = {"F110",
 "F101",
 "F011"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = { }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, spyProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; string Arr2[] = {"F11000",
 "S00011",
 "F10100",
 "S01111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.8, 0.4, 0.4, 0.2, 0.2 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, spyProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 3; string Arr2[] = {"S100001100",
 "F011110000",
 "F001000010",
 "F100010101",
 "S010010001",
 "F100001010",
 "F000100100"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.3, 0.1, 0.4, 0.5, 0.2, 0.1, 0.6, 0.7, 0.1 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, spyProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    Resistance ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
