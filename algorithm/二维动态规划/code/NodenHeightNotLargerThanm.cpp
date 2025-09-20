//https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<vector<long>>dp(51,vector<long>(51));
int solve1(int n,int m){
    if(n==0)return 1;
    if(m==0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    long ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+(long)solve1(i,m-1)*solve1(n-i-1,m-1)%mod)%mod;
    }
    dp[n][m]=ans;
    return (int)ans;

}

int solve2(int n,int m){
    for(int j=0;j<=m;j++){
        dp[0][j]=1;
    }
    for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = 0;
				for (int k = 0; k < i; k++) {
					dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % mod) % mod;
				}
			}
		}
	return (int) dp[n][m];
}
vector<int>dp3(51);
int solve3(int n, int m) {
		dp3[0] = 1;
		for (int i = 1; i <= n; i++) {
			dp3[i] = 0;
		}
		for (int j = 1; j <= m; j++) {
			// 根据依赖，一定要先枚举列
			for (int i = n; i >= 1; i--) {
				// 再枚举行，而且i不需要到达0，i>=1即可
				dp3[i] = 0;
				for (int k = 0; k < i; k++) {
					// 枚举
					dp3[i] = (dp3[i] + dp3[k] * dp3[i - k - 1] % mod) % mod;
				}
			}
		}
		return (int) dp3[n];
	}
int main(){
    int n,m;
    cin>>n>>m;
    // for(int i=0;i<=50;i++){
    //     for(int j=0;j<=50;j++){
    //         dp[i][j]=-1;
    //     }
    // }
    cout<<solve2(n,m);
    return 0;
}
