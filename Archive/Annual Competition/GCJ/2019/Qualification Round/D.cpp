#include <bits/stdc++.h>
using namespace std;

string ask(const string &s, const int m)
{
    printf("%s\n", s.c_str());
    fflush(stdout);
    char t[m+1] = {};
    scanf("%s", t);
    return string(t);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        m = n-m;
        string s[10];
        for(int i = 0; i < k; i++){
            string t;
            for(int j = 0; j < n; j++){
                if(j>>i&1)t += "1";
                else t += "0";
            }
            s[i] = ask(t, m);
        }
        bool ok[n] = {};
        for(int i = 0; i < m; i++){
            int v = 0;
            for(int j = 0; j < 10; j++){
                if(s[j][i] == '1')v += 1<<j;
            }
            ok[v] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!ok[i])printf("%d%c", i, " \n"[++cnt==n-m]);
        }
        fflush(stdout);
        scanf("%*d");
    }
    return 0;
}

