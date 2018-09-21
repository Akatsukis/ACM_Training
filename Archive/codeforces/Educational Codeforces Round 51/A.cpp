#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
int tot[3];

int id(char c)
{
    if(isupper(c))return 0;
    else if(islower(c))return 1;
    else return 2;
}

char get(int x)
{
    if(x == 0)return 'A';
    else if(x == 1)return 'a';
    else return '0';
}

int main()
{
    int T; sc(T);
    while(T--){
        memset(tot, 0, sizeof(tot));
        string s;
        cin >> s;
        for(auto c : s){
            tot[id(c)]++;
        }
        int zero = 0;
        for(int i = 0; i < 3; i++){
            if(!tot[i])zero++;
        }
        if(!zero)cout << s << endl;
        else if(zero == 1){
            for(int i = 0; i < SZ(s); i++){
                if(tot[id(s[i])] > 1){
                    for(int j = 0; j < 3; j++){
                        if(!tot[j]){
                            s[i] = get(j);
                            break;
                        }
                    }
                    break;
                }
            }
            cout << s << endl;
        }
        else{
            for(int i = 0; i < 3; i++){
                if(!tot[i]){
                    s[0] = get(i);
                    tot[i]++;
                    break;
                }
            }
            for(int i = 0; i < 3; i++){
                if(!tot[i]){
                    s[1] = get(i);
                    tot[i]++;
                    break;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}

