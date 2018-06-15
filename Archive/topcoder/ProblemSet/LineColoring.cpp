// BEGIN CUT HERE  
/* 

*/  
// END CUT HERE  
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
bool vis[maxn];
priority_queue<pii> pq;

class LineColoring  
{  
    public:  
        int minCost(vector <int> x)  
        {  
            memset(vis, 0, sizeof(vis));
            int n = x.size(), ret = 0;
            while(1){
                for(int i = 0; i < n; i++){
                    if(!vis[i])pq.push(mk(x[i], i));
                }
                set<int> st;
                pii p = pq.top(); pq.pop();
                st.insert(p.se);
                vis[p.se] = 1;
                ret += p.fi;
                while(!pq.empty()){
                    p = pq.top(); pq.pop();
                    if(!st.count(p.se-1) && !st.count(p.se+1)){
                        vis[p.se] = 1;
                        st.insert(p.se);
                    }
                }
                bool flg = 1;
                for(int i = 0; i < n; i++){
                    if(!vis[i]){
                        flg = 0;
                        break;
                    }
                }
                if(flg)break;
            }
            return ret;
        }  

        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { int Arr0[] = {1,2,3,4,5,6,7,8,9}
            ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minCost(Arg0)); }
        void test_case_1() { int Arr0[] = {7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, minCost(Arg0)); }
        void test_case_2() { int Arr0[] = {1,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minCost(Arg0)); }
        void test_case_3() { int Arr0[] = {1,10,1,1,1,1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, minCost(Arg0)); }
        void test_case_4() { int Arr0[] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
            ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 33; verify_case(4, Arg1, minCost(Arg0)); }
        void test_case_5() { int Arr0[] = {1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; verify_case(5, Arg1, minCost(Arg0)); }
        void test_case_6() { int Arr0[] = {9450,7098,6048,1050,672,8232,5028,
            672,672,42,42,42,42,42,9450,6048,
            3402,3402,2688,9450,7098,6048,1050,
            672,8232,5028,672,672,9450,6048,3402}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18900; verify_case(6, Arg1, minCost(Arg0)); }

        // END CUT HERE

};  

// BEGIN CUT HERE  
int main()  
{  
    LineColoring ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
