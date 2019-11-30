#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        long long sum = 0;
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            sum += x;
            if(sum%2 && k > 1) {
                k--;
                ans.push_back(i);
                sum = 0;
            }
        }
        if(k == 1 && sum%2) {
            puts("YES");
            ans.push_back(n);
            for(int i = 0; i < (int)ans.size(); i++) {
                printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
            }
        }
        else puts("NO");
    }
    return 0;
}

