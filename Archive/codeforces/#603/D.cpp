#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6+10;
int par[maxn];
char s[maxn];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        par[x] = y;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    iota(par, par+n+26, 0);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        for(int j = 0; j < len; j++) {
            unite(s[j]-'a', i+26);
        }
    }
    set<int> st;
    for(int i = 0; i < n; i++) {
        if(!st.count(find(i+26))) {
            st.insert(find(i+26));
        }
    }
    printf("%d\n", (int)st.size());
    return 0;
}

