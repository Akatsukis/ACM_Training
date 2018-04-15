#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> v1, v2, v3;

int main()
{
    for(int i = 0; i < 5; i++){
        cout<<i*5+1<<" "<<i*5+2<<" "<<i*5+3<<" "<<i*5+4<<" "<<i*5+5<<endl;
        cout<<flush;
        for(int j = 1; j <= 5; j++){
            int t;
            cin >> t;
            if(t == 1)v1.pb(i*5+j);
            if(t == 2)v2.pb(i*5+j);
        }
    }
    int ans1 = 0, ans2 = 0;
    cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2]<<" "<<v1[3]<<" "<<v1[4]<<endl;
    cout<<flush;
    for(int j = 0; j < 5; j++){
        int t;
        cin>>t;
        if(t == 1)ans1 = v1[j], v3.pb(v2[j]);
        if(t == 2)v3.pb(v1[j]);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= 25; j++){
            bool flg = 1;
            for(int k = 0; k < (int)v3.size(); k++){
                int u = v3[k];
                if(j == u || j == ans1){
                    flg = 0;
                    break;
                }
            }
            if(flg){
                v3.pb(j);
                break;
            }
        }
    }
    cout<<v3[0]<<" "<<v3[1]<<" "<<v3[2]<<" "<<v3[3]<<" "<<v3[4]<<endl;
    cout<<flush;
    for(int i = 0; i < 5; i++){
        int t;
        cin>>t;
        if(t == 1)ans2 = v3[i];
    }
    cout<<ans1<<" "<<ans2<<" "<<0<<" "<<0<<" "<<0<<endl;
    cout<<flush;
    return 0;
}

