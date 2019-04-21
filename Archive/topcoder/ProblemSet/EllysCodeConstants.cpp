// BEGIN CUT HERE  
 

// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class EllysCodeConstants  
{  
    public:  
    string getLiteral(string s)  
    {
        map<char, char> mp;
        mp['O'] = '0';
        mp['I'] = '1';
        mp['Z'] = '2';
        mp['S'] = '5';
        mp['T'] = '7';
        for(char i = 'A'; i <= 'F'; i++)mp[i] = i;
        bool ok = 0;
        string ans = "0x";
        vector<string> vec{"L", "LL", "U", "UL", "ULL", "LU", "LLU"};
        for(int i = 0; i < (int)s.size(); i++){
            if(isdigit(s[i])){
                ans += s[i];
                ok = 1;
            }
            else if(mp.count(s[i])){
                ans += mp[s[i]];
                ok = 1;
            }
            else{
                if(!ok)return string();
                else ok = 0;
                for(auto t: vec){
                    if(t == s.substr(i)){
                        ok = 1;
                        ans += s.substr(i);
                        break;
                    }
                }
                break;
            }
        }
        if(ok)return ans;
        else return string();
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); if ((Case == -1) || (Case == 10)) test_case_10(); if ((Case == -1) || (Case == 11)) test_case_11(); if ((Case == -1) || (Case == 12)) test_case_12(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DEADBEEF"; string Arg1 = "0xDEADBEEF"; verify_case(0, Arg1, getLiteral(Arg0)); }
	void test_case_1() { string Arg0 = "BABACECA"; string Arg1 = "0xBABACECA"; verify_case(1, Arg1, getLiteral(Arg0)); }
	void test_case_2() { string Arg0 = "TOPCODER"; string Arg1 = ""; verify_case(2, Arg1, getLiteral(Arg0)); }
	void test_case_3() { string Arg0 = "FLU"; string Arg1 = "0xFLU"; verify_case(3, Arg1, getLiteral(Arg0)); }
	void test_case_4() { string Arg0 = "FULL"; string Arg1 = "0xFULL"; verify_case(4, Arg1, getLiteral(Arg0)); }
	void test_case_5() { string Arg0 = "FALL"; string Arg1 = "0xFALL"; verify_case(5, Arg1, getLiteral(Arg0)); }
	void test_case_6() { string Arg0 = "TASTEFUL"; string Arg1 = "0x7A57EFUL"; verify_case(6, Arg1, getLiteral(Arg0)); }
	void test_case_7() { string Arg0 = "OFFICIAL"; string Arg1 = "0x0FF1C1AL"; verify_case(7, Arg1, getLiteral(Arg0)); }
	void test_case_8() { string Arg0 = "OOZE"; string Arg1 = "0x002E"; verify_case(8, Arg1, getLiteral(Arg0)); }
	void test_case_9() { string Arg0 = "ESPRIT"; string Arg1 = ""; verify_case(9, Arg1, getLiteral(Arg0)); }
	void test_case_10() { string Arg0 = "COOL"; string Arg1 = "0xC00L"; verify_case(10, Arg1, getLiteral(Arg0)); }
	void test_case_11() { string Arg0 = "DISEASE"; string Arg1 = "0xD15EA5E"; verify_case(11, Arg1, getLiteral(Arg0)); }
	void test_case_12() { string Arg0 = "SOLVED"; string Arg1 = ""; verify_case(12, Arg1, getLiteral(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE
int main()  
{
    EllysCodeConstants ___test;
    ___test.run_test(-1);
    return 0;
}  
// END CUT HERE

