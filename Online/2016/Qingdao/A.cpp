#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
typedef long long ll;
set<ll> st;

void init()
{
    queue<ll> q;
    q.push(1);
    st.insert(1);
    while(!q.empty()){
        ll u = q.front(); q.pop();
        if(u > 1e9)continue;
        if(!st.count(u*2)){
            st.insert(u*2);
            q.push(u*2);
        }
        if(!st.count(u*3)){
            st.insert(u*3);
            q.push(u*3);
        }
        if(!st.count(u*5)){
            st.insert(u*5);
            q.push(u*5);
        }
        if(!st.count(u*7)){
            st.insert(u*7);
            q.push(u*7);
        }
    }
}

int main()
{
    int T;
    sc(T);
    init();
    while(T--){
        int n;
        sc(n);
        int ans = *st.lower_bound(n);
        printf("%d\n", ans);
    }
    return 0;
}
