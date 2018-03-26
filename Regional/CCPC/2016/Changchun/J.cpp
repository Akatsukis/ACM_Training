#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
const int maxn = 1010;
string s;

string sub(string p, string q)
{
    int n = p.size(), m = q.size();
//    for(int i = 0; i < n; i++){
//        printf("%c", p[i]+'0');
//    }
//    printf("-");
//    for(int i = 0; i < m; i++){
//        printf("%c", q[i]+'0');
//    }
//    printf("=");
    bool flag = 0;
    int i = 0;
    for(i = 0; i < m; i++){
        if(flag){
            p[i]--;
            flag = 0;
        }
        if(p[i] < q[i]){
            flag = 1;
            p[i] = p[i]+10-q[i];
        }
        else p[i] = p[i]-q[i];
    }
    while(flag){
        p[i]--;
        flag = 0;
        if(p[i] < 0){
            flag = 1;
            p[i] = p[i]+10;
        }
        i++;
    }
    while(n>1 && p[n-1] == 0){
        p.pop_back();
        n--;
    }
    p.resize(n);
//    for(int i = 0; i < n; i++){
//        printf("%c", p[i]+'0');
//    }
//    puts("");
    return p;
}
string add(string p, string q)
{
    int n = p.size(), m = q.size();
    bool flag = 0;
    int i = 0;
    for(i = 0; i < m; i++){
        if(flag){
            p[i]++;
            flag = 0;
        }
        if(p[i]+q[i]>=10){
            flag = 1;
            p[i] = p[i]+q[i]-10;
        }
        else p[i] = p[i]+q[i];
    }
    while(flag){
        if(i == n){
            p = p+"1";
            n++;
            p[n-1] -= '0';
            break;
        }
        p[i]++;
        flag = 0;
        if(p[i] >= 10){
            flag = 1;
            p[i] -= 10;
        }
        i++;
    }
    return p;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        cin >> s;
        int sz = s.size();
        for(int i = 0; i < sz; i++)s[i]-='0';
        reverse(s.begin(), s.end());
        printf("Case #%d:\n", kase++);
        vector<string> ans;
        while(sz != 1 || s[0] != 0){
            bool flag = 0;
            if(s[0] == 0){
                flag = 1;
                string t = "1";
                t[0] -= '0';
                s = sub(s, t);
            }
            sz = s.size();
            string tmp;
            if(sz&1){
                bool flg = 0;
                tmp = tmp+s[sz/2];
                for(int i = sz/2-1, j = sz/2+1; i >= 0 && j < sz; i--, j++){
                    char c = 0;
                    if(flg)c = s[i];
                    else if(s[i] > s[j]){
                        flg = 1;
                        c = s[j];
                    }
                    else c = s[i];
                    tmp = c+tmp+c;
                }
            }
            else{
                bool flg = 0;
                for(int i = sz/2-1, j = sz/2; i >= 0 && j < sz; i--, j++){
                    char c = 0;
                    if(flg)c = s[i];
                    else if(s[i] > s[j]){
                        flg = 1;
                        c = s[j];
                    }
                    else c = s[i];
                    tmp = c+tmp+c;
                }
            }
            ans.pb(tmp);
//            for(int i = 0; i < tmp.size(); i++){
//                printf("%c", tmp[i]+'0');
//            }
//            puts("");
            if(flag){
                string t = "1";
                t[0] -= '0';
                s = add(s, t);
            }
            s = sub(s, tmp);
//            for(int i = 0; i < s.size(); i++){
//                printf("%c", s[i]+'0');
//            }
//            puts("");
            sz = s.size();
        }
        cout << ans.size() << endl;
        for(int i = 0; i < (int)ans.size(); i++){
            reverse(ans[i].begin(), ans[i].end());
            for(int j = 0; j < (int)ans[i].size(); j++){
                printf("%c", ans[i][j]+'0');
            }
            puts("");
        }
    }
}
