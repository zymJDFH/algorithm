//https://leetcode.cn/problems/0i0mDW/description/

//递归
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       return f(grid,m-1,n-1);
    }
    int f(vector<vector<int>>& grid,int i,int j){
        if(i==0&&j==0){
            return grid[0][0];
        }
        int up=INT_MAX;
        int left=INT_MAX;
        if(i>=1){
            up=f(grid,i-1,j);
        }
        if(j>=1){
            left=f(grid,i,j-1);
        }
        return min(up,left)+grid[i][j];
    }
};

//记忆化搜索
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>>dp(m,vector<int>(n));
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = -1;
                }
            }
       return f(grid,m-1,n-1,dp);
    }
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0){
            return dp[0][0]=grid[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=INT_MAX;
        int left=INT_MAX;
        if(i>=1){
            up=f(grid,i-1,j,dp);
        }
        if(j>=1){
            left=f(grid,i,j-1,dp);
        }
        return dp[i][j]=min(up,left)+grid[i][j];
    }
};
//动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
        
    }
};

//动态规划+空间压缩
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n);
        dp[0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+grid[0][i];
        }     
        for(int i=1;i<m;i++){
            dp[0]+=grid[i][0];
            for(int j=1;j<n;j++){
                dp[j]=min(dp[j-1],dp[j])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};