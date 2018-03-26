#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
const int mod = 1000000007;
const int maxn = 20010;
bool del[maxn];
int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(del, 0, sizeof(del));
        int n, p;
        sc(n); sc(p);
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            ans.pb(i);
        }
        if(n&1){
            swap(ans[n-1], ans[n-2]);
            for(int i = 2, j = n-3; i <= p; i++, j -= 2){
                ans.pb(j);
                del[j-1] = 1;
            }
        }
        else{
            for(int i = 2, j = n-2; i <= p; i++, j -= 2){
                ans.pb(j);
                del[j-1] = 1;
            }
        }
        printf("Case #%d: ", kase++);
        for(int i = 0; i < (int)ans.size(); i++){
            if(!del[i])printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
        }
    }
}
