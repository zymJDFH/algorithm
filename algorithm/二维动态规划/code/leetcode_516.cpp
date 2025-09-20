class Solution {
public:
    int longestPalindromeSubseq(string s) {
       int n=s.size();
       return f(s,0,n-1);
    }
    int f(string &s,int l,int r){
        if(l==r){
            return 1;
        }
        if(l+1==r){
            return s[l]==s[r]?2:1;
        }
        if(s[l]==s[r]){
            return f(s,l+1,r-1)+2;
        }
        else if(s[l]!=s[r]){
            return max(f(s,l+1,r),f(s,l,r-1));
        }
        return 0;
    }
};
//记忆化搜索
class Solution {
public:
    int longestPalindromeSubseq(string s) {
       int n=s.size();
       vector<vector<int>>dp(n,vector<int>(n));
       return f(s,0,n-1,dp);
    }
    int f(string &s,int l,int r,vector<vector<int>>&dp){
        if(l==r){
            return 1;
        }
        if(l+1==r){
            return s[l]==s[r]?2:1;
        }
        if(dp[l][r]){
            return dp[l][r];
        }
        int ans;
        if(s[l]==s[r]){
            ans= f(s,l+1,r-1,dp)+2;
        }
        else if(s[l]!=s[r]){
           ans= max(f(s,l+1,r,dp),f(s,l,r-1,dp));
        }
        return  dp[l][r]=ans;
    }
};

//dp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
       int n=s.size();
       vector<vector<int>>dp(n,vector<int>(n));
        for(int l=n-1;l>=0;l--){
            dp[l][l]=1;
            if(l+1<n){
                dp[l][l+1]=s[l]==s[l+1]?2:1;
            }
            for (int r = l + 2; r < n; r++) {
				if (s[l] == s[r]) {
					dp[l][r] = 2 + dp[l + 1][r - 1];
				} else {
					dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
				}
			}
        }
        return dp[0][n-1];
    } 
};