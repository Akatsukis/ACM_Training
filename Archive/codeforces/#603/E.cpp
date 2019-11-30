#include <bits/stdc++.h>
using namespace std;
#define lson k*2+1
#define rson k*2+2
constexpr int maxn = 1e6+10;
char s[maxn], buf[maxn];
int mx[maxn*4], mn[maxn*4], tag[maxn*4], sum[maxn*4];

void update1(int a, int k, int l, int r, int val) {
    if(l == r-1) {
        sum[k] += val;
        return;
    }
    int m = (l+r)/2;
    if(a < m) update1(a, lson, l, m, val);
    else update1(a, rson, m, r, val);
    sum[k] = sum[lson]+sum[rson];
}

void pushdown(int k, int l, int r) {
    if(l != r-1 && tag[k]) {
        tag[lson] += tag[k]; tag[rson] += tag[k];
        mx[lson] += tag[k]; mx[rson] += tag[k];
        mn[lson] += tag[k]; mn[rson] += tag[k];
        tag[k] = 0;
    }
}

void update2(int a, int b, int k, int l, int r, int val) {
    if(a >= r || b <= l)return;
    if(a <= l && b >= r) {
        mx[k] += val;
        mn[k] += val;
        tag[k] += val;
        return;
    }
    pushdown(k, l, r);
    int m = (l+r)/2;
    update2(a, b, lson, l, m, val);
    update2(a, b, rson, m, r, val);
    mx[k] = max(mx[lson], mx[rson]);
    mn[k] = min(mn[lson], mn[rson]);
}


int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') cur = max(cur-1, 0);
        else if(s[i] == 'R') cur++;
        else {
            if(buf[cur] == '(') {
                update1(cur, 0, 0, n, -1);
                update2(cur, n, 0, 0, n, -1);
            }
            else if(buf[cur] == ')') {
                update1(cur, 0, 0, n, 1);
                update2(cur, n, 0, 0, n, 1);
            }
            if(s[i] == '(') {
                update1(cur, 0, 0, n, 1); 
                update2(cur, n, 0, 0, n, 1); 
            }
            else if(s[i] == ')') {
                update1(cur, 0, 0, n, -1);
                update2(cur, n, 0, 0, n, -1);
            }
            buf[cur] = s[i];
        }
        int ans;
        if(sum[0] != 0 || mn[0] < 0) ans = -1;
        else ans = mx[0];
        printf("%d%c", ans, " \n"[i==n-1]);
    }
    return 0;
}

