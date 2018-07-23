#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int maxn = 1e5+10;
int mx[maxn];
int ans[maxn];
set<int> st;

int main()
{
    int T; sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        st.clear();
        for(int i = 1; i <= n; i++)mx[i] = i, ans[i] = 0;
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            mx[u] = max(mx[u], v);
        }
        int pos = 1;
        for(int i = 1; i <= n; i++)st.insert(i);
        for(int i = 1; i <= n; i++){
            if(pos <= mx[i]){
                for(int j = pos; j <= mx[i]; j++){
                    ans[j] = *st.begin();
                    
                    st.erase(st.begin());
                }
                pos = mx[i]+1;
            }
            st.insert(ans[i]);
        }
        for(int i = 1; i <= n; i++){
            printf("%d%c", ans[i], " \n"[i==n]);
        }
    }
}
