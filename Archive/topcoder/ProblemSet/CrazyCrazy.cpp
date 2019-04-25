// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class CrazyCrazy  
{  
    public:  
    string possible(string song)  
    {
        int n = song.size()/2;
        set<string> st;
        for(int i = 0; i < (1<<n); i++){
            string s1, s2;
            for(int j = 0; j < n; j++){
                if(i>>j&1)s1 += song[j];
                else s2 += song[j];
            }
            bool ok = 1;
            int k = 0;
            if(s1.size() < s2.size())swap(s1, s2);
            while(k < (int)s2.size()){
                if(s1[k] != s2[k]){
                    ok = 0;
                    break;
                }
                else k++;
            }
            if(ok)st.insert(s1.substr(k));
        }
        for(int i = 0; i < (1<<n); i++){
            string s1, s2;
            for(int j = 0; j < n; j++){
                if(i>>j&1)s1 += song[j+n];
                else s2 += song[j+n];
            }
            bool ok = 1;
            if(s1.size() < s2.size())swap(s1, s2);
            int k1 = s1.size(), k2 = s2.size();
            while(k2 >= 0){
                if(s1[k1] != s2[k2]){
                    ok = 0;
                    break;
                }
                else k1--, k2--;
            }
            if(ok && st.count(s1.substr(0, k1+1)))return "possible";
            
        }
        return "impossible";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabb" ; string Arg1 = "possible"; verify_case(0, Arg1, possible(Arg0)); }
	void test_case_1() { string Arg0 = "abba" ; string Arg1 = "impossible"; verify_case(1, Arg1, possible(Arg0)); }
	void test_case_2() { string Arg0 = "verylazyverylazy" ; string Arg1 = "possible"; verify_case(2, Arg1, possible(Arg0)); }
	void test_case_3() { string Arg0 = "arqmpfvvbtltlhufznkldkurrazmgebfxeamrewn" ; string Arg1 = "impossible"; verify_case(3, Arg1, possible(Arg0)); }
	void test_case_4() { string Arg0 = "aacfcfqqsmksimkoioeertbrtbhphnpnggddjjll" ; string Arg1 = "possible"; verify_case(4, Arg1, possible(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    CrazyCrazy ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

