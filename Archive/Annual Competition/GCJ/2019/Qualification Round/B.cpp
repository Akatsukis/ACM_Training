#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        for(auto &c : s){
            if(c == 'E')c = 'S';
            else c = 'E';
        }
        cout << "Case #" << kase++ << ": " << s << endl;
    }
    return 0;
}

