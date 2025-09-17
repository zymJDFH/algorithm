class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>dp(n);
        int ans=0;
        if(n==0)return 0;
        dp[0]=0;
        for(int i=1;i<n;i++){
            if(s[i]=='(')dp[i]=0;
            else{
                int x=dp[i-1];
                if(i-x-1>=0&&s[i-x-1]=='('){
                    dp[i]=x+2;
                    if(i-x-2>=0)dp[i]+=dp[i-2-x];
                }
            }
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};