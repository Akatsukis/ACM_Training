#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
string s, t;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    cin >> s;
    t = s;
    for(int i = 0; i < k; i++) {
        for(int j = i; j < n; j += k) {
            t[j] = s[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] > t[i]) {
            int pos = 0;
            for(int j = min(i, k-1); j >= 0; j--) {
                if(t[j] != '9') {
                    for(int h = j; h < n; h += k) {
                        t[h]++;
                    }
                    pos = j+1;
                    break;
                }
            }
            for(int j = pos; j < k; j++) {
                for(int h = j; h < n; h += k) {
                    t[h] = '0';
                }
            }
            break;
        }
        else if(s[i] < t[i]) {
            break;
        }
    }
    printf("%d\n", n);
    cout << t << endl;
    return 0;
}

