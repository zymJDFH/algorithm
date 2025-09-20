class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        return f(s1,s2,n-1,m-1);
    }
    int f(string s1,string s2,int i,int j){
        if(i<0||j<0){
            return 0;
        }
        int p1=f(s1,s2,i-1,j);
        int p2=f(s1,s2,i,j-1);
        int p3=f(s1,s2,i-1,j-1);
        int p4=p1+(s1[i]==s2[j]);
        return max(max(p1,p2),max(p3,p4));
    }
};

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        return f(s1,s2,n,m);
    }
    int f(string s1,string s2,int len1,int len2){
       if(len1==0||len2==0){
        return 0;
       }
       if(s1[len1-1]==s2[len2-1]){
         return f(s1,s2,len1-1,len2-1)+1;
       }
       else{
        return max(f(s1,s2,len1,len2-1),f(s1,s2,len1-1,len2));
       }
    }
};

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        return f(s1,s2,n,m,dp);
    }
    int f(string &s1,string &s2,int len1,int len2,vector<vector<int>>&dp){
       if(len1==0||len2==0){
        return 0;
       }
       if(dp[len1-1][len2-1]!=-1){
        return dp[len1-1][len2-1];
       }

       if(s1[len1-1]==s2[len2-1]){
         return dp[len1-1][len2-1]=f(s1,s2,len1-1,len2-1,dp)+1;
       }
       else{
        return dp[len1-1][len2-1]=max(f(s1,s2,len1,len2-1,dp),f(s1,s2,len1-1,len2,dp));
       }
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};