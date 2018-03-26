#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        sc(n);
        vector<int> vec;
        int tot = 0;
        for(int i = 1; i <= n; i++){
            if(tot < 3 || vec[tot-1]+vec[tot-2]<=i)vec.pb(i), tot++;
        }
        printf("Case #%d: %d\n", kase++, n-tot);
    }
}
