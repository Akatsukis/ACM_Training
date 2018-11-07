#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
const int maxn = 2e5+10;
map<pair<pii, int>, int> mp1;
map<pii, int> mp2;
set<pii> id1, id2;
int par1[maxn], par2[maxn];
int cnt1, cnt2;

int find(int x, int *arr)
{
    return arr[x] == x ? x : arr[x] = find(arr[x], arr);
}

bool unite(int x, int y, int *arr, int id)
{
    if(id == 1){
        if(x == y || id1.count(mk(x, y)))return 1;
    }
    else{
        if(x == y || id2.count(mk(x, y)))return 1;
    }
    if(id == 1)id1.insert(mk(x, y)), id1.insert(mk(y, x));
    else id2.insert(mk(x, y)), id2.insert(mk(y, x));
    x = find(x, arr), y = find(y, arr);
    if(x != y){
        arr[x] = y;
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 3*n; i++)par1[i] = par2[i] = i;
    bool flg1 = 1, flg2 = 1;;
    for(int i = 1; i <= n; i++){
        int x1, y1, z1, x2, y2, z2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        if(!mp1.count(mk(mk(x1, y1), z1)))mp1[mk(mk(x1, y1), z1)] = ++cnt1;
        if(!mp1.count(mk(mk(x2, y2), z2)))mp1[mk(mk(x2, y2), z2)] = ++cnt1;
        if(!unite(mp1[mk(mk(x1, y1), z1)], mp1[mk(mk(x2, y2), z2)], par1, 1))flg1 = 0;
        if(!mp2.count(mk(x1, y1)))mp2[mk(x1, y1)] = ++cnt2;
        if(!mp2.count(mk(x2, y2)))mp2[mk(x2, y2)] = ++cnt2;
        if(!unite(mp2[mk(x1, y1)], mp2[mk(x2, y2)], par2, 2))flg2 = 0;
    }
    if(flg1)puts("No true closed chains");
    else puts("True closed chains");
    if(flg2)puts("No floor closed chains");
    else puts("Floor closed chains");
    return 0;
}
