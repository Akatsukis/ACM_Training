#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
#define debug cout<<"STOP"<<endl;
#define fastio ios::sync_with_stdio(false), cin.tie(0)

string solve(string s)
{
    if(s=="10")return "9";
    int sz = s.size();
    bool flag = 1;
    for(int i = 0, j = sz-1; i < j; i++, j--){
        if(s[i] > s[j]){
            flag = 0;
            break;
        }
    }
    string ret = s;
    if(!flag){
        int pos = sz%2?sz/2:sz/2-1;
        ret[pos]--;
        while(ret[pos] < '0'){
            ret[pos] += 10;
            ret[pos-1]--;
            pos--;
        }
        if(!pos && ret[pos] == '0')ret = ret.substr(1, sz-1);
        sz=ret.size();
    }
    for(int i = 0, j = sz-1; i < j; i++, j--)ret[j] = ret[i];
    return ret;
}

string sub(string a, string b)
{
    string ret;
    int sa = a.size(), sb = b.size();
    int i = sa-1, j = sb-1;
    for(; j >= 0; i--, j--){
        char c = 0;
        if(a[i] >= b[j])c = a[i]-b[j]+'0';
        else{
            c = a[i]-b[j]+10+'0';
            int k = i-1; a[k]--;
            while(a[k] < '0'){
                a[k] += 10;
                a[k-1]--;
                k--;
            }
        } 
        ret = c+ret;
    }
    while(i >= 0){
        ret = a[i]+ret;
        i--;
    }
    while((int)ret.size() > 1 && ret[0] == '0')ret = ret.substr(1, (int)ret.size()-1);
    return ret;
}

int main()
{
    int T, kase = 1;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        vector<string> ans;
        int sz = s.size();
        while(sz != 1 || s[0] != '0'){
            string t = solve(s);
            ans.pb(t);
            s = sub(s, t);
            sz = s.size();
        }
        cout << "Case #" << kase++ << ":" << endl;
        cout << ans.size() << endl;
        for(int i = 0; i < (int)ans.size(); i++){
            cout << ans[i] << endl;
        }
    }
}
