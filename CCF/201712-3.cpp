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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 22;

struct Command
{
    char minutes[100], hours[100], day[100];
    char month[100], week[100];
    char command[100];
}com[maxn];

int char_to_num(const char* s, int p, int q)
{
    int ret = 0;
    for(int i = p; i <= q; i++){
        ret = ret*10+s[i]-'0';
    }
    return ret;
}

bool ok(int mat, const char* s)
{
    int len = strlen(s);
    int l = 0, r = 0;
    bool flag = 0;//flag = 1 includes '-'
    bool num = 0;
    if(s[0] == '*')return true;
    for(int i = 0; i < len;){
        if(s[i] == ','){
            if(flag == 1){
                if(mat >= l && mat <= r)return true;
            }
            else{
                if(mat == l)return true;
            }
            l = r = 0;
            flag = num = 0;
            i++;
        }
        else if(s[i] == '-'){
            flag = 1;
            i++;
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            int tmp = 0;
            if(s[i]=='J'&&s[i+1]=='a'&&s[i+2]=='n')tmp = 1;
            if(s[i]=='F'&&s[i+1]=='e'&&s[i+2]=='b')tmp = 2;
            if(s[i]=='M'&&s[i+1]=='a'&&s[i+2]=='r')tmp = 3;
            if(s[i]=='A'&&s[i+1]=='p'&&s[i+2]=='r')tmp = 4;
            if(s[i]=='M'&&s[i+1]=='a'&&s[i+2]=='y')tmp = 5;
            if(s[i]=='J'&&s[i+1]=='u'&&s[i+2]=='n')tmp = 6;
            if(s[i]=='J'&&s[i+1]=='u'&&s[i+2]=='l')tmp = 7;
            if(s[i]=='A'&&s[i+1]=='u'&&s[i+2]=='g')tmp = 8;
            if(s[i]=='S'&&s[i+1]=='e'&&s[i+2]=='p')tmp = 9;
            if(s[i]=='O'&&s[i+1]=='c'&&s[i+2]=='t')tmp = 10;
            if(s[i]=='N'&&s[i+1]=='o'&&s[i+2]=='v')tmp = 11;
            if(s[i]=='D'&&s[i+1]=='e'&&s[i+2]=='c')tmp = 12;
            if(s[i]=='S'&&s[i+1]=='u'&&s[i+2]=='n')tmp = 0;
            if(s[i]=='M'&&s[i+1]=='o'&&s[i+2]=='n')tmp = 1;
            if(s[i]=='T'&&s[i+1]=='u'&&s[i+2]=='e')tmp = 2;
            if(s[i]=='W'&&s[i+1]=='e'&&s[i+2]=='d')tmp = 3;
            if(s[i]=='T'&&s[i+1]=='h'&&s[i+2]=='u')tmp = 4;
            if(s[i]=='F'&&s[i+1]=='r'&&s[i+2]=='i')tmp = 5;
            if(s[i]=='S'&&s[i+1]=='a'&&s[i+2]=='t')tmp = 6;
            if(!flag)l = tmp;
            else r = tmp;
            num = 1;
            i += 3;
        }
        else{
            if(!flag)l = l*10+s[i]-'0';
            else r = r*10+s[i]-'0';
            num = 1;
            i++;
        }
    }
    if(num == 1 && flag == 1 && mat >= l && mat <= r)return true;
    else if(num == 1 && flag == 0 && mat == l)return true;
    return false;
}
struct Date
{
    int year, month, day;
    int hour, minute, week;
    Date operator + (const int rhs)
    {
        minute += rhs;
        if(minute == 60)minute = 0, hour++;
        if(hour == 24)hour = 0, day++, week++;
        if(week==7)week = 0;
        if(month == 2){
            if(year%4==0&&(year%100!=0||year%400==0)){
                if(day == 30)day = 1, month++;
            }
            else{
                if(day == 29)day = 1, month++;
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11){
            if(day == 31)day = 1, month++;
        }
        else{
            if(day == 32)day = 1, month++;
        }
        if(month == 13)year++, month = 1;
        return *this;
    }
    bool operator < (const Date &rhs)const
    {
        if(year != rhs.year)return year < rhs.year;
        if(month != rhs.month)return month < rhs.month;
        if(day != rhs.day)return day < rhs.day;
        if(hour != rhs.hour)return hour < rhs.hour;
        if(minute != rhs.minute)return minute < rhs.minute;
        return false;
    }
    bool operator == (const Command &rhs)const
    {
        if(ok(minute, rhs.minutes)&&ok(hour, rhs.hours)&&ok(day, rhs.day)&&ok(month, rhs.month)&&ok(week, rhs.week))return true;
        return false;
    }
    void trs(const char* s)
    {
        year = char_to_num(s, 0, 3);
        month = char_to_num(s, 4, 5);
        day = char_to_num(s, 6, 7);
        hour = char_to_num(s, 8, 9);
        minute = char_to_num(s, 10, 11);
        int ret = 0;
        for(int i = 1970; i < year; i++){
            if((i%4==0)&&(i%100!=0||i%400==0))ret += 366;
            else ret += 365;
        }
        for(int i = 1; i < month; i++){
            if(i == 2){
                if((i%4==0)&&(i%100!=0||i%400==0))ret += 29;
                else ret += 28;
            }
            else if(i==4||i==6||i==9||i==11)ret += 30;
            else ret += 31;
        }
        ret += day-1;
        ret += 4;
        week = ret%7;
    }
    void output()
    {
        printf("%04d%02d%02d%02d%02d", year, month, day, hour, minute);
    }
};

int main()
{
    int n;
    char s[15], t[15];
    scanf("%d%s%s", &n, s, t);
    Date st, ed;
    st.trs(s), ed.trs(t);
    for(int i = 0; i < n; i++){
        scanf("%s%s%s%s%s%s", com[i].minutes, com[i].hours, com[i].day, com[i].month, com[i].week, com[i].command);
    }
    for(Date i = st; i < ed; i=i+1){
        for(int j = 0; j < n; j++){
            if(i == com[j]){
                i.output();
                printf(" %s\n", com[j].command);
            }
        }
    }
    return 0;
}

