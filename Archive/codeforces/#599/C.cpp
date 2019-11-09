#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 5e3+10;
const int maxk = 16;
vector<int> box[maxn];
unordered_map<long long, int> blg;
pair<int, int> pre[1<<maxk];
pair<int, int> mask[1<<maxk];
long long sum[maxn], avg;
bool dp[1<<maxk];
vector<pair<int, int>> ans;

bool dfs(long long need, long long target, int &flg) {
    if(need == target) {
        return 1;
    }
    if(!blg.count(need) || flg>>blg[need]&1) {
        return 0;
    }
    int boxId = blg[need];
    need = avg-(sum[boxId]-need);
    flg |= 1<<boxId;
    return dfs(need, target, flg);
}

int main()
{
    int n;
    scanf("%d", &n);
    long long tot = 0;
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        box[i] = vector<int>(k);
        for(auto &num: box[i]) {
            scanf("%d", &num);
            blg[num] = i;
            sum[i] += num;
        }
        tot += sum[i];
    }
    if(tot%n != 0) {
        puts("No");
        return 0;
    }
    avg = tot/n;
    for(int i = 0; i < (1<<n); i++) {
        mask[i] = {-1, -1};
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (int)box[i].size(); j++) {
            long long need = avg-(sum[i]-box[i][j]);
            int flg = 1<<i;
            if(dfs(need, box[i][j], flg)) {
                mask[flg] = make_pair(i, j);
            }
        }
    }
    dp[0] = 1;
    int all = (1<<n);
    for(int S = 1; S < all; S++) {
        int nS = S;
        while(nS) {
            if(mask[nS] != make_pair(-1, -1) && dp[S^nS]) {
                dp[S] = 1;
                pre[S] = mask[nS];
                break;
            }
            nS = (nS-1)&S;
        }
    }
    int S = all-1;
    if(!dp[S]) {
        puts("No");
        return 0;
    }
    ans = vector<pair<int, int>>(n);
    while(S) {
        int i = pre[S].first, j = pre[S].second;
        int pre = box[i][j], nxt = avg-(sum[i]-pre);
        int curId = i, flg = 1<<i;
        while(nxt != box[i][j]) {
            int nxtId = blg[nxt];
            ans[nxtId] = make_pair(nxt, curId);
            curId = nxtId;
            flg |= 1<<curId;
            pre = nxt; nxt = avg-(sum[nxtId]-pre);
        }
        ans[i] = make_pair(nxt, curId);
        S = S^flg;
    }
    puts("Yes");
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second+1);
    }
    return 0;
}
