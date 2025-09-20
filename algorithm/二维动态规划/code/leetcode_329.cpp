class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(matrix,i,j));
            }
        }
        return ans;
    }
    int f(vector<vector<int>>& matrix,int i,int j){
        int step=0;
        if(j>0&&matrix[i][j]<matrix[i][j-1]){
            step=max(step,f(matrix,i,j-1));
        }
         if(j<matrix[0].size()-1&&matrix[i][j]<matrix[i][j+1]){
            step=max(step,f(matrix,i,j+1));
        } if(i>0&&matrix[i][j]<matrix[i-1][j]){
            step=max(step,f(matrix,i-1,j));
        } if(i<matrix.size()-1&&matrix[i][j]<matrix[i+1][j]){
            step=max(step,f(matrix,i+1,j));
        }
        return step+1;
    }
};

//记忆化搜索
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(matrix,i,j,dp));
            }
        }
        return ans;
    }
    int f(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        int step=0;
        if(dp[i][j]){
            return dp[i][j];
        }
        if(j>0&&matrix[i][j]<matrix[i][j-1]){
            step=max(step,f(matrix,i,j-1,dp));
        }
         if(j<matrix[0].size()-1&&matrix[i][j]<matrix[i][j+1]){
            step=max(step,f(matrix,i,j+1,dp));
        } if(i>0&&matrix[i][j]<matrix[i-1][j]){
            step=max(step,f(matrix,i-1,j,dp));
        } if(i<matrix.size()-1&&matrix[i][j]<matrix[i+1][j]){
            step=max(step,f(matrix,i+1,j,dp));
        }
        
        return dp[i][j]=step+1;
    }
};