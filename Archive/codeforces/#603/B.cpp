#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        vector<string> s(n);
        multiset<string> all;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            all.insert(s[i]);
        }
        for(int i = 0; i < n; i++) {
            all.erase(find(all.begin(), all.end(), s[i]));
            if(all.count(s[i])) {
                ans++;
                for(int j = 0; j < 4; j++) {
                    string t = s[i];
                    for(int k = 0; k < 10; k++) {
                        t[j] = k+'0';
                        if(!all.count(t)) {
                            s[i] = t;
                            break;
                        }
                    }
                    if(!all.count(t)) {
                        all.insert(t);
                        break;
                    }
                }
            }
            else all.insert(s[i]);
        }
        printf("%d\n", ans);
        for(int i = 0; i < n; i++) {
            cout << s[i] << endl;
        }

    }
    return 0;
}

