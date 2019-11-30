#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i += 2) {
        if(s[i] == s[i+1]) {
            ans++;
            if(s[i] == 'a')s[i+1] = 'b';
            else s[i+1] = 'a';
        }
    }
    cout << ans << endl << s << endl;
    return 0;
}
