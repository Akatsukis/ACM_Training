#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, kase = 1;
    scanf("%d\n", &T);
    while(T--){
        string s;
        cin >> s;
        bool z1 = 1, z2 = 1;
        string t1, t2;
        for(auto c : s){
            int v = c-'0';
            if(v == 0){
                if(!z1)t1 += "0";
                if(!z2)t2 += "0";
            }
            else if(v == 1){
                if(z1){
                    z1 = 0;
                    t1 += "1";
                }
                else if(z2){
                    z2 = 0;
                    t1 += "0"; t2 += "1";
                }
                else t1 += "1", t2 += "0";
            }
            else{
                z1 = z2 = 0;
                for(int i = 1; i < 10; i++){
                    int j = v-i;
                    if(i == 4 || j == 4)continue;
                    char c1 = i+'0', c2 = j+'0';
                    t1 += c1; t2 += c2;
                    break;
                }
            }
        }
        cout << "Case #" << kase++ << ": " << t1 << " " << t2 << endl;
    }
    return 0;
}

