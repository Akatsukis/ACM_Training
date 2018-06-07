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
const long double eps = 1e-15;
const int maxn = 510;
const int maxm = 10;
int w[maxm];
int ans[maxn];
int score[maxn][maxm];
int mx[maxm];
int rnd[maxn];
struct atom
{
    long double score;
    int id;
    bool operator < (const atom &rhs)const
    {
        return score > rhs.score;
    }
}arr[maxn];

int main()
{
    int n, m, k, c;
    scanf("%d%d%d%d", &n, &m, &k, &c);
    for(int i = 0; i < m; i++)sc(w[i]);
    int posx = 0, posy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &score[i][j]);
            if(score[i][j] == -1)posx = i, posy = j;
        }
    }
    for(int i = 0; i <= c; i++){
        score[posx][posy] = i;
        memset(mx, 0, sizeof(mx));
        memset(arr, 0, sizeof(arr));
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                mx[j] = max(mx[j], score[k][j]);
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(mx[k])arr[j].score += 1.0*w[k]*score[j][k]/mx[k];
            }
            arr[j].id = j;
        }
        sort(arr, arr+n);
        long double tmp = arr[k-1].score;
        bool flag = abs(arr[k-1].score-arr[k].score)<eps&&k!=n?1:0;
        for(int j = 0; j < n; j++){
            if(flag && abs(arr[j].score-tmp)<eps)rnd[arr[j].id] = 1;
            else if(j < k)ans[arr[j].id]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(rnd[i]){
            printf("3\n");
            continue;
        }
        if(ans[i] == c+1)printf("1\n");
        else if(ans[i] == 0)printf("2\n");
        else printf("3\n");
    }
    return 0;
}

