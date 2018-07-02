// BEGIN CUT HERE

// END CUT HERE
#line 5 "QuadraticIdentity.cpp"
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
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
class QuadraticIdentity
{
    public:
    vector<long long> getFixedPoints(long long m)
    {
        vector<ll> ans;
        ans.pb(0); ans.pb(1);
        for(ll i = 2; i*(i-1) <= m; i++){
            if(i*(i-1)%m==0){
                for(ll j = i; j <= m; j += i){
                    ans.pb(j);
                }
            }
        }
        sort(ALL(ans));
        int n = ans.size();
        int gap = 1;
        while(n/gap > 500){
            gap *= 2;
        }
        vector<ll> ret;
        for(int i = 0; i < n; i += gap){
            ret.pb(ans[i]);
        }
        return ret;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 20LL; long Arr1[] = {0, 1, 5, 16 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getFixedPoints(Arg0)); }
	void test_case_1() { long long Arg0 = 4262046602LL; long Arr1[] = {0, 1, 27391046, 152613648, 180004693, 333799345, 361190390, 513804038, 541195083, 621181264, 648572309, 801185957, 828577002, 941255910, 968646955, 982371654, 1009762699, 1121260603, 1148651648, 1162376347, 1189767392, 1302446300, 1329837345, 1482450993, 1509842038, 1589828219, 1617219264, 1769832912, 1797223957, 1951018609, 1978409654, 2103632256, 2131023301, 2131023302, 2158414347, 2283636949, 2311027994, 2464822646, 2492213691, 2644827339, 2672218384, 2752204565, 2779595610, 2932209258, 2959600303, 3072279211, 3099670256, 3113394955, 3140786000, 3252283904, 3279674949, 3293399648, 3320790693, 3433469601, 3460860646, 3613474294, 3640865339, 3720851520, 3748242565, 3900856213, 3928247258, 4082041910, 4109432955, 4234655557 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getFixedPoints(Arg0)); }
	void test_case_2() { long long Arg0 = 7LL; long Arr1[] = {0, 1 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getFixedPoints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    QuadraticIdentity test;
    test.run_test(-1);
}
// END CUT HERE
