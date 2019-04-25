#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
using namespace std;
const int mod = 1e9+7; 
const int SZ = 1e3+10;;
int dp[SZ][SZ];
 
int main(int argc, char *argv[]) {
	int n;
	while (cin >> n) {
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 0;
		dp[1][1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j + 1< i) dp[i][j] += (dp[i][j]+dp[i-1][j+1])%mod;
				if (j > 0) dp[i][j] += (dp[i][j]+dp[i-1][j-1])%mod;
			}
		}
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n/2; j++){
                ans = (ans+dp[i][j])%mod;
            }
        }
		cout << ans << endl;
	}
	return 0;
}

