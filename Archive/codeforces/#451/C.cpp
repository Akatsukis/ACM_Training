#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
map<string, vector<string> > mp;

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int k;
        sc(k);
        for(int j = 0; j < k; j++){
            string t;
            cin >> t;
            mp[s].pb(t);
        }
    }
    printf("%d\n", (int)mp.size());
    for(auto it = mp.begin(); it != mp.end(); it++){
        int del[300];
        memset(del, 0, sizeof(del));
        for(int i = 0; i < (int)it->se.size(); i++){
            for(int j = 0; j < (int)it->se.size(); j++){
                if(i==j || del[j])continue;
                for(int k = 0; k < (int)it->se[j].size(); k++){
                    if(it->se[j].substr(k, it->se[j].size()-k) == it->se[i]){
                        del[i] = 1;
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < (int)it->se.size(); i++){
            if(!del[i])ans++;
        }
        cout << (it->fi) << " " << ans << " ";
        for(int i = 0; i < (int)it->se.size(); i++){
            if(!del[i])cout << it->se[i] << " ";
        }
        cout << endl;
    }
	return 0;
}

