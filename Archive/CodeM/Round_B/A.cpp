#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
const int maxm = 5e2+10;
struct Time
{
    int hh, mm, s1, s2;
    bool operator < (const Time &rhs)const
    {
        if(hh != rhs.hh)return hh < rhs.hh;
        else if(mm != rhs.mm)return mm < rhs.mm;
        else if(s1 != rhs.s1)return s1 < rhs.s1;
        else return s2 < rhs.s2;
    }
};
struct atom
{
    int x, y, z;
    Time t;
    bool operator < (const atom &rhs)const
    {
        return t < rhs.t;
    }
}tb[maxn];
int mp[maxm][maxm];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        int x, y, z, hh, mm, s1, s2;
        scanf("%d %d %d %d:%d:%d.%d", &x, &y, &z, &hh, &mm, &s1, &s2);
        tb[i].x = x, tb[i].y = y, tb[i].z = z;
        tb[i].t.hh = hh, tb[i].t.mm = mm, tb[i].t.s1 = s1, tb[i].t.s2 = s2;
    }
    sort(tb, tb+k);
    int mx = 0, now = 0, ans = 0;;
    for(int i = 0; i < k; i++){
        if(tb[i].z){
            mp[tb[i].x][tb[i].y]--;
            if(!mp[tb[i].x][tb[i].y])now--;
        }
        else{
            mp[tb[i].x][tb[i].y]++;
            if(mp[tb[i].x][tb[i].y] == 1)now++;
        }
        if(now >= mx){
            now = mx;
            ans = i;
        }
    }
    memset(mp, 0, sizeof(mp));
    for(int i = 0; i <= ans; i++){
        if(tb[i].z)mp[tb[i].x][tb[i].y]--;
        else mp[tb[i].x][tb[i].y]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j])putchar('1');
            else putchar('0');
        }
        printf("\n");
    }
    return 0;
}

