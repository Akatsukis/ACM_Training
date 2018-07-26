#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
bool vis[maxn];
vector<int> p;
int n;

void init()
{
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            p.push_back(i);
            for(int j = 2*i; j <= n; j += i)vis[j] = 1;
        }
    }
}

int main()
{
    scanf("%d", &n);
    init();
    long long ans = 0;
    for(int i = 1; i < (int)p.size(); i++){
        ans += 1LL*n/p[i]*i*2;
    }
    printf("%lld\n", ans);
}
