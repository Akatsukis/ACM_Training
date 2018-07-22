// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
  
class SquareCutout  
{  
    public:  
    int verify(vector <string> cutout)  
    {  
        int n = cutout.size(), m = cutout[0].size();
        int x = -1, y = -1;            
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cutout[i][j] == '#'){
                    x = i, y = j;
                    break;
                }
            }
            if(x != -1 && y != -1)break;
        }
        if(x == -1 && y == -1)return 1;
        int tx = 1, ty = 1;
        while(x+tx < n && cutout[x+tx][y] == '#')tx++;
        while(y+ty < m && cutout[x][y+ty] == '#')ty++;
        bool flg = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i >= x && i < x+tx && j >= y && j < y+ty){
                    if(cutout[i][j] == '.'){
                        flg = 0;
                        break;
                    }
                }
                else{
                    if(cutout[i][j] == '#'){
                        flg = 0;
                        break;
                    }
                }
            }
            if(!flg)break;
        }
        if(tx < ty && x != 0 && x+tx != n)flg = 0;
        if(tx > ty && y != 0 && y+ty != m)flg = 0;
        if(flg)return max(tx, ty);
        else return 0;
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..##.",
 "..##.",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, verify(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, verify(Arg0)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, verify(Arg0)); }
	void test_case_3() { string Arr0[] = {"..####",
 "..####",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, verify(Arg0)); }
	void test_case_4() { string Arr0[] = {"..#..",
 ".###.",
 "#####",
 ".###.",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, verify(Arg0)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    SquareCutout ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
