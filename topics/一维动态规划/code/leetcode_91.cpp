//https://leetcode.cn/problems/decode-ways/

//递归
class Solution {
public:
    int cal(const string&s,int pos){
        int n=s.size();
        if(pos==n){
            return 1;
        }
        int ans;
        if(s[pos]=='0'){
            ans=0;
        }else{
            ans=0;
            ans+=cal(s,pos+1);
            if(pos+1<n&&(s[pos]-'0')*10+(s[pos+1]-'0')<=26){
                ans+=cal(s,pos+2);
            }
        }
        return ans;
    }
    int numDecodings(string s) {
        return cal(s,0);
    }
};

//记忆化搜索
class Solution {
public:
    int dp[105];
    int cal(const string&s,int pos){
        int n=s.size();
        if(pos==n){
            return 1;
        }
        if(dp[pos]!=-1){
            return dp[pos];
        }
        int ans;
        if(s[pos]=='0'){
            ans=0;
        }else{
            ans=0;
            ans+=cal(s,pos+1);
            if(pos+1<n&&(s[pos]-'0')*10+(s[pos+1]-'0')<=26){
                ans+=cal(s,pos+2);
            }
        }
        dp[pos]=ans;
        return dp[pos];
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return cal(s,0);
    }
};

//动态规划
class Solution {
public:
    int dp[105];
    int numDecodings(string s) {
       
        int n=s.size();
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
             
                dp[i]+=dp[i+1];
                if(i+1<n&&(s[i]-'0')*10+(s[i+1]-'0')<=26){
                    dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
    }
};
