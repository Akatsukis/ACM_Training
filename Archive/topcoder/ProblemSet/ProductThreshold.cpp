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
#define Abs(x) ((x)>=0?(x):(-(x)))
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
  
class ProductThreshold  
{  
    public:  
    vector<ll> vec;
    int sum[maxn];
    int nxt[maxn];
    long long subarrayCount(int N, int limit, vector <int> Aprefix, int spread, int offset)  
    {  
        vec.clear();
        memset(sum, 0, sizeof(sum));
        memset(nxt, 0, sizeof(nxt));
        int p = Aprefix.size();
        for(int i = 0; i < p; i++)vec.pb(Aprefix[i]);
        ll seed = Abs(Aprefix[p-1]);
        for(int i = p; i < N; i++){
            seed = (seed*1103515245+12345)%(1<<31);
            vec.pb(seed%spread+offset);
        }
        sum[0] = vec[0] < 0;
        nxt[N-1] = vec[N-1]<0?N-1:0;
        for(int i = 1; i < N; i++)sum[i] = sum[i-1]+(vec[i]<0);
        for(int i = N-2; i >= 0; i--){
            if(vec[i] < 0)nxt[i] = i;
            else nxt[i] = nxt[i+1];
        }
        ll now = 1, ans = 0;
        int l = 0, r = 0, sgn = 1;
        for(; l < N; ){
            if(now > limit || r == N){
                ans += r-l;
                if(sgn)ans += r==0?sum[N-1]/2:(sum[N-1]-sum[r-1])/2;
                else{
                    if(nxt[r]){
                        int pos = nxt[r];
                        ans += pos-r;
                        ans += (sum[N-1]-sum[pos])/2;
                    }
                    else ans += N-r;
                }
                now /= Abs(vec[l]);
                sgn *= vec[l]>=0?1:-1;
                l++;
                printf("ans=%lld\n", ans);
            }
            else{
                now *= Abs(vec[r]);
                sgn *= vec[r]>=0?1:-1;
                r++;
            }
        }
        return ans;
    }  
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,2,3,-4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 1; long long Arg5 = 13LL; verify_case(0, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 8; int Arr2[] = {2,2,2,2,2,2,2,2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 47; long long Arg5 = 27LL; verify_case(1, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 999888777; int Arr2[] = {47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7654321; int Arg4 = 1; long long Arg5 = 21LL; verify_case(2, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 8; int Arr2[] = {3,0,3,0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; int Arg4 = 47; long long Arg5 = 15LL; verify_case(3, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 1; int Arr2[] = {-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 2; long long Arg5 = 1000LL; verify_case(4, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 47; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 1; long long Arg5 = 5050LL; verify_case(5, Arg5, subarrayCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
    ProductThreshold ___test;  
    ___test.run_test(-1);  
    return 0;  
}  
// END CUT HERE  
