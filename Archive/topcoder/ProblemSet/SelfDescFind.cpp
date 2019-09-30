#include <bits/stdc++.h>
using namespace std;
  
class SelfDescFind  
{  
    public:  
    bool check(int id, int n, vector<int> &num, vector<int> &digits, vector<int> &tot) {
        for(int i = 0; i < id; i++){
            if(num[digits[i]]+(n-id) < tot[digits[i]])return 0; 
        }
        return 1;
    }
    void dfs(int id, int n, vector<int> &num, vector<int> &digits, vector<int> &tot, string &ans) {
        if(!check(id, n, num, digits, tot))return;
        if(id == n) {
            vector<string> vec;
            for(int i = 0; i < n; i++){
                if(tot[digits[i]] != num[digits[i]])return;
                char c = tot[digits[i]]+'0', d = digits[i]+'0';
                string s;
                s += c; s += d;
                vec.push_back(s);
            }
            sort(vec.begin(), vec.end());
            string cur;
            for(auto s: vec)cur += s;
            if(ans.empty())ans = cur;
            else ans = min(ans, cur);
            return;
        }
        if(digits[id] == 0){
            num[0]++; num[1]++; tot[0] = 1;
            dfs(id+1, n, num, digits, tot, ans);
            num[0]--; num[1]--; tot[0] = 0;
        }
        else{
            for(int i = 0; i < n; i++){
                num[digits[i]]++; num[digits[id]]++; tot[digits[id]] = digits[i];
                dfs(id+1, n, num, digits, tot, ans);
                num[digits[i]]--; num[digits[id]]--; tot[digits[id]] = 0;
            }
        }
    }
    string construct(vector <int> digits)  
    {
        vector<int> num(10, 0), tot(10, 0);
        int n = digits.size();
        string ans;
        dfs(0, n, num, digits, tot, ans);
        return ans;
    }
    
  
};


int main()
{
    vector<int> vec{0,1,2,3,4,5,7,8,9};
    SelfDescFind solver;
    string ans = solver.construct(vec);
    cout << ans << endl;
}

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
