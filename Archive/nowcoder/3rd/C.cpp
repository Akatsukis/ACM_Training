#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<int> r;

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)r.push_back(i);
    for(int i = 0; i < q; i++){
        int l, c;
        scanf("%d%d", &l, &c);
        r = r.substr(l-1, c)+r.substr(0, l-1)+r.substr(l+c-1, n+1-l-c);
    }
    for(int i = 0; i < n; i++)printf("%d%c", r[i], " \n"[i==n]);
}
