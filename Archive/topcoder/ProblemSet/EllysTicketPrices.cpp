#include <bits/stdc++.h>
using namespace std;
  
class EllysTicketPrices  
{  
    public:  
    long long get(int st, int n, vector<int> C)
    {
        long long tot = st, cur = st;
        for(auto u: C){
            double tmp = double(cur)*(100+u)/100;
            cur = round(tmp);
            tot += cur;
        }
        double tmp = double(tot)/n;
        long long ans = round(tmp);
        return ans;
    }
    double getPrice(int N, vector <int> C, int target)  
    {
        long long l = 0, r = 1e9, ans = 0;
        while(l <= r){
            long long m = (l+r)>>1;
            if(get(m, N, C) >= target*100){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return double(ans/100.0);
    }
    
  
};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
