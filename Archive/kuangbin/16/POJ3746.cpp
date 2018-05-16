#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
map<string, char> fun;
map<string, char> word;
map<string, char> str;
map<string, bool> ste;

void init()
{
    fun["n."] = '1'; 
    fun["pron."] = '2'; 
    fun["adj."] = '3'; 
    fun["adv."] = '4'; 
    fun["prep."] = '5'; 
    fun["art."] = '6'; 
    fun["vt."] = '7'; 
    fun["vi."] = '8'; 
    fun["v."] = '9';
    str["61"] = str["631"] = str["2"] = 'S';
    str["8"] = str["48"] = 'I';
    str["7"] = str["47"] = 'T';
    str["9"] = str["49"] = 'V';
    str["52"] = str["561"] = str["5631"] = 'A';
    ste["SI"] = ste["STS"] = ste["SV"] = ste["SVS"] = 1;
    ste["ASI"] = ste["ASTS"] = ste["ASV"] = ste["ASVS"] = 1;
    ste["SAI"] = ste["SATS"] = ste["SAV"] = ste["SAVS"] = 1;
    ste["SIA"] = ste["STAS"] = ste["SVA"] = ste["SVAS"] = 1;
    ste["STSA"] = ste["SVSA"] = 1;
}

int main()
{
    int n, m;
    init();
    while(cin >> n >> m){
        word.clear();
        for(int i = 0; i < n; i++){
            string s, t;
            cin >> s >> t;
            word[s] = fun[t];
        }
        for(int i = 0; i < m; i++){
            string u, v, s;
            while(cin >> s){
                for(int j = 0; j < (int)s.size(); j++)s[j] = tolower(s[j]);
                if(s[(int)s.size()-1] == '.'){
                    s = s.substr(0, (int)s.size()-1);
                    v += word[s];
                    if(str[v])u += str[v], v = "";
                    break;
                }
                else if(s[(int)s.size()-1] == ','){
                    s = s.substr(0, (int)s.size()-1);
                    v += word[s];
                    if(str[v])u += str[v], v = "";
                }
                else v += word[s];
                if(str[v])u += str[v], v = "";
            }
            if(v.size())u += str[v], v = "";
            if(ste[u])puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

