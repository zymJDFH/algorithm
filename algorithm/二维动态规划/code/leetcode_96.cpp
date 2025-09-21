class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size(),b=s2.size(),c=s3.size();
        if(a+b!=c)return false;
        vector<vector<bool>>dp(a+1,vector<bool>(b+1));
        dp[0][0]=true;
        for(int i=1;i<=a;i++){
            if(s1[i-1]!=s3[i-1]){
                break;
            }
            dp[i][0]=true;
        }
        for(int i=1;i<=b;i++){
            if(s2[i-1]!=s3[i-1]){
                break;
            }
            dp[0][i]=true;
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                dp[i][j]=(s1[i-1]==s3[i+j-1]&&dp[i-1][j])||(s2[j-1]==s3[i+j-1]&&dp[i][j-1]);
            }
        }
        return dp[a][b];
    }   
};