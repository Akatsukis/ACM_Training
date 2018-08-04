#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define lson k*2+1
#define rson k*2+2
const int maxn = 1e5+10;
int mx[maxn*4], tag[maxn*4], sum[maxn*4];
int val[maxn];

void build(int k, int l, int r)
{
    if(l == r-1){
        mx[k] = -val[l];
        sum[k] = tag[k] = 0;
        return;
    }
    int m = (l+r)/2;
    build(lson, l, m);
    build(rson, m, r);
    mx[k] = max(mx[lson], mx[rson]);
    sum[k] = tag[k] = 0;
}

void pushdown(int k, int l, int r)
{
    if(tag[k] && l != r-1){
        mx[lson] += tag[k];
        mx[rson] += tag[k];
        tag[lson] += tag[k];
        tag[rson] += tag[k];
        tag[k] = 0;
    }
}

void update(int a, int b, int k, int l, int r)
{
    if(a >= r || b <= l)return;
    if(a <= l && b >= r){
        if(mx[k]+1 >= 0){
            if(l == r-1){
                mx[k] = -val[l];
                sum[k]++;
            }
            else{
                int m = (l+r)/2;
                pushdown(k, l, r);
                update(a, b, lson, l, m);
                update(a, b, rson, m, r);
                mx[k] = max(mx[lson], mx[rson]);
                sum[k] = sum[lson]+sum[rson];
            }
        }
        else{
            mx[k]++;
            tag[k]++;
        }
        return;
    }
    pushdown(k, l, r);
    int m = (l+r)/2;
    update(a, b, lson, l, m);
    update(a, b, rson, m, r);
    mx[k] = max(mx[lson], mx[rson]);
    sum[k] = sum[lson]+sum[rson];
}

int query(int a, int b, int k, int l, int r)
{
    if(a >= r || b <= l)return 0;
    else if(a <= l && b >= r)return sum[k];
    pushdown(k, l, r);
    int m = (l+r)/2;
    int v1 = query(a, b, lson, l, m);
    int v2 = query(a, b, rson, m, r);
    return v1+v2;
}

int main()
{
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 0; i < n; i++)sc(val[i]);
        build(0, 0, n);
        for(int i = 0; i < q; i++){
            char s[10];
            int l, r;
            scanf("%s%d%d", s, &l, &r);
            if(s[0] == 'a'){
                update(l-1, r, 0, 0, n);
            }
            else{
                int ans = query(l-1, r, 0, 0, n);
                printf("%d\n", ans);
            }
        }
    }
}
