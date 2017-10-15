#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double DINF = 1e9;
const double eps = 1e-4;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e3+100;
#define MAXN 20000

double x[MAXN],y[MAXN];
double l[MAXN];
double r[MAXN];
double a[MAXN],b[MAXN];//a<=r<=b
int n;
double A,B,C;

double len(int i,int j){
    return sqrt((y[i]-y[j])*(y[i]-y[j]) + (x[i]-x[j])*(x[i]-x[j]));
}

int sgn(double x){
    if(fabs(x)<=eps){
        return 0;
    }
    else if(x<0)
        return -1;
    else
        return 1;
}

void add_21(double m,double n)
{
    A += m*m;
    B += 2*m*n;
    C += n*n;
}

double getmax(double a,double b){
    double mid = (-B)/(2*A);
    if(sgn(mid-a)>=0 && sgn(b-mid)>=0)
        return mid;
    else if(sgn(a-mid)>=0)
        return a;
    else
        return b;
}

bool solve()
{
    A = B = C = 0;
    add_21(1,0);
    a[0] = 0;   b[0] = min(l[0],l[n-1]);
    double cur = 0,k=1;
    for(int i=1; i<n; i++){
        cur = l[i-1]-cur;
        k = -1*k;
        add_21(k,cur);
        b[i] = min(l[i],l[i-1])-cur;
        a[i] = -cur;
        if(k<0){
            a[i] *= -1;
            b[i] *= -1;
            swap(a[i],b[i]);
        }
    }
    double L=-DINF,R=DINF;
    for(int i=0; i<n; i++)
    {
        L = max(a[i],L);
        R = min(b[i],R);
    }
    //cout<<"L: "<<L<<"R: "<<R<<endl;
    if(sgn(R-L)<0)
        return 0;
    else{
        r[0] =  getmax(L,R);
        return 1;
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i=0; i<n; i++){
            scanf("%lf%lf",x+i,y+i);
        }
        x[n] = x[0];  y[n] = y[0];
        for(int i=0; i<n; i++){
            l[i] = len(i,i+1);
        }
        double sum = 0;
        double k = 1;
        for(int i=n-1; i>=0; i--){
            sum += k*l[i];
            k = k*-1;
        }
        //cout<<"sum: "<<sum<<endl;
        if(n%2==0){
            if(sgn(sum)!=0 || !solve()){
                printf("IMPOSSIBLE\n");
                continue;
            }
        }
        else
            r[0] = sum/2;
        for(int i=1; i<n; i++)
            r[i] = l[i-1] - r[i-1];

        bool flag = true;
        for(int i=0; i<n; i++)
            if(sgn(r[i])<0) flag = false;
        if(!flag){
            printf("IMPOSSIBLE\n");
            continue;
        }

        double ans = 0;
        for(int i=0; i<n; i++)
            ans += r[i]*r[i];
        ans *= PI;
        printf("%.2f\n",ans);
        for(int i=0; i<n; i++)
            printf("%.2f\n",r[i]);
    }
}
