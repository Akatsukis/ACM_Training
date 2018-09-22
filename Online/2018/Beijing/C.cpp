#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> VI;
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
const int maxn = 20;
int num[maxn][maxn], tot[maxn];
char s[maxn];
vector<int> tb;
int zidian[maxn]={10,2,3,4,5,6,7,8,9,1,11,13,12};

int enc(char c)
{
    if(isdigit(c)){
        if(c == '1')return 10;
        else return c-'0';
    }
    else if(c == 'A')return 1;
    else if(c == 'J')return 11;
    else if(c == 'Q')return 12;
    else return 13;
}

void init()
{
	tb.clear();
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++)num[i][j] = 0;
        tot[i] = 0;
    }
}

bool draw()
{
    if(scanf("%s", s) == EOF)return 0;
    init();
    num[0][enc(s[0])]++; tot[0]++;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            if(!i && !j)continue;
            scanf("%s", s);
            num[i][enc(s[0])]++;
            tot[i]++;
        }
    }
    return 1;
}

int getlexi(int id)
{
    if(num[id][10])return 10;
    for(int i = 2; i <= 9; i++)if(num[id][i])return i;
    if(num[id][1])return 1;
    if(num[id][11])return 11;
    if(num[id][13])return 13;
    if(num[id][12])return 12;
    return -1;
}

VI play(int id, int card)
{
    if(id == 0){
        VI re;
        if(num[id][card]){
            re.pb(card);
            num[id][card]--; tot[id]--;
            return re;
        }
        else{
            int t = getlexi(id);
            re.pb(t);
            num[id][t]--, tot[id]--;
            return re;
        }
    }
    else if(id == 1){
        if(num[id][card]){
        	VI re;
        	tot[id] -= num[id][card];
        	while(num[id][card])re.pb(card),num[id][card]--;
        	return re;
        }
        else{
            VI re;
            int t = getlexi(id);
            re.pb(t);
            num[id][t]--, tot[id]--;
            return re;
        }
    }
    else if(id == 2){
        if(num[id][card]){
        	VI re;
        	tot[id] -= num[id][card];
        	while(num[id][card])re.pb(card),num[id][card]--;
        	return re;
		}
		else {
			int minTimes=2e9;
			for(int i=1;i<=13;i++)
				if(num[id][i])minTimes=min(minTimes,num[id][i]);
				
			int v;
			for(int i=0;i<13;i++)
				if(num[id][zidian[i]]==minTimes){v=zidian[i];break;}
			VI re;
			tot[id] -= num[id][v];
			while(num[id][v])re.pb(v),num[id][v]--;
			return re;
		}
    }
    else {
    	if(num[id][card]>=3){
        	VI re;
        	tot[id] -= num[id][card];
        	while(num[id][card])re.pb(card),num[id][card]--;
        	return re;
		}
		else{
			VI re;
        	tot[id] -= num[id][card];
        	while(num[id][card])re.pb(card),num[id][card]--;
			int mn=getlexi(id);
			if(mn==-1)return re;
			tot[id]--;
			num[id][mn]--;
			re.pb(mn);
			return re;
		}
	}
}

bool ok(vector<int> vec, int card)
{
    for(auto u : vec)if(u != card)return 0;
    return 1;
}

bool challenge(int size,int id,int card,int ifnext,int now){
	if(id == 0){
		if(ifnext && !num[id][card%13+1])return 1;
		if(size + num[id][card] > 4)return 1;
		return 0;
	}
	else if(id == 1){
		if(ifnext && !num[id][card%13+1])return 1;
		return 0;
	}
	else if(id == 2){
		if(num[id][card] == 4)return 1;
		return 0;
	}
	else {
		if(!now)return 1;
		return 0;
	}
}

string decode(int t)
{
	if(t==1)return "A";
	if(t==11)return "J";
	if(t==12)return "Q";
	if(t==13)return "K";
	if(t==10)return "10";
	string re="";
	char c='0'+t;
	return re+c;
}

int main()
{
    while(draw()){
        int card = 1, player = 0;
        while(1){
            VI vec = play(player, card);
            for(auto u : vec)tb.pb(u);
            for(int i = 1; i < 4; i++){
                int chaer = (player+i)%4;
                if(challenge(vec.size(),chaer,card,(i==1),tot[player])){
                    if(ok(vec, card)){
                        for(auto u : tb){
                            num[chaer][u]++;
                            tot[chaer]++;
                        }
                    }
                    else{
                        for(auto u : tb){
                            num[player][u]++;
                            tot[player]++;
                        }
                    }
                    tb.clear();
                    break;
                }
            }
            if(tot[player] == 0)break;
            player = (player+1)%4, card = card%13+1;
        }
        for(int i=0;i<4;i++)
        	if(!tot[i])printf("WINNER\n");
        	else{
        		int f=0;
				for(int j=1;j<=13;j++)
        			for(int k=1;k<=num[i][j];k++){
        				if(f)cout<<" "<<decode(j);
        				else cout<<decode(j),f=1;
        			}
        		cout<<endl;
        	}
        for(int i = 0; i < 4; i++){
            for(int j = 1; j <= 13; j++){
                tot[i] -= num[i][j];
            }
            //assert(tot[i] == 0);
        }
    }    
    return 0;
}
