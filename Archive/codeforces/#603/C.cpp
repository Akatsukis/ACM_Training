#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        vector<int> ans;
        int cur = n+1;
        while(cur >= 1) {
            ans.push_back(n/cur);
            int l = 1, r = n+1, nxt = 0;
            while(l <= r) {
                int m = (l+r)/2;
                if(n/m >= n/cur+1) {
                    nxt = m;
                    l = m+1;
                }
                else r = m-1;
            }
            cur = nxt;
        }
        printf("%d\n", (int)ans.size());
        for(int i = 0; i < (int)ans.size(); i++) {
            printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
        }
    }
    return 0;
}

