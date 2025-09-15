//https://leetcode.cn/problems/decode-ways-ii/description/

//纯暴力
class Solution {
public:
    const int mod=1e9+7;
    int f(const string &s,int i){
        int n=s.size();
        int ans=0;
        if(s[i]=='0')return 0;
        if(i==n)return 1;
        if(s[i]!='*'){
            ans+=f(s,i+1);
            if(i+1<n){
                if(s[i+1]=='*'){
                    if(s[i]=='1'){
                        ans+=9*f(s,i+2);
                    }
                    if(s[i]=='2'){
                        ans+=6*f(s,i+2);
                    }
                }else{
                    if((s[i]-'0')*10+(s[i+1]-'0')<=26){
                        ans+=f(s,i+2);
                    }
                }
            }

        }else{
            ans+=9*f(s,i+1);
            if(i+1<n){
                 if(s[i+1]=='*'){
                   ans+=15*f(s,i+2);
                }else{
                    if(s[i+1]>'6'){
                        ans+=f(s,i+2);
                    }else{
                        ans+=2*f(s,i+2);
                    }
                }
            }
        }
        return ans;
    }
    int numDecodings(string s) {
        return f(s,0);
    }
};

//记忆化搜索
class Solution {
public:
    const int mod=1e9+7;
    int dp[100005];
    int f(const string &s,int i){
        int n=s.size();
        long long ans=0;
        if(s[i]=='0')return 0;
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i]!='*'){
            ans+=f(s,i+1);
            if(i+1<n){
                if(s[i+1]=='*'){
                    if(s[i]=='1'){
                        ans+=9ll*f(s,i+2);
                    }
                    if(s[i]=='2'){
                        ans+=6ll*f(s,i+2);
                    }
                }else{
                    if((s[i]-'0')*10+(s[i+1]-'0')<=26){
                        ans+=f(s,i+2);
                    }
                }
            }

        }else{
            ans+=9ll*f(s,i+1);
            if(i+1<n){
                 if(s[i+1]=='*'){
                   ans+=15ll*f(s,i+2);
                }else{
                    if(s[i+1]>'6'){
                        ans+=f(s,i+2);
                    }else{
                        ans+=2ll*f(s,i+2);
                    }
                }
            }
        }
        ans%=mod;
        dp[i]=ans;
        return ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(s,0);
    }
};

//动态规划
class Solution {
public:
    const int mod=1e9+7;
    
    int numDecodings(string s) { 
        int n=s.size();
        vector<long> dp(n + 2, 0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
           if(s[i]!='0'){
                dp[i]=(s[i]=='*'?9:1)*dp[i+1];
                if(i+1<n){
                    if(s[i]=='*'){
                        if(s[i+1]=='*'){
                            dp[i]+=15*dp[i+2];
                        }else{
                            if(s[i+1]>'6'){
                               dp[i]+=dp[i+2];
                            }else{
                                dp[i]+=2*dp[i+2];
                            }
                        }
                    }else{
                        if(s[i+1]=='*'){
                            if(s[i]=='1'){
                                dp[i]+=9*dp[i+2];
                            }
                            if(s[i]=='2'){
                                dp[i]+=6*dp[i+2];
                            }
                        }else{
                            if((s[i]-'0')*10+(s[i+1]-'0')<=26){
                                dp[i]+=dp[i+2];
                            }
                        }
                    }
                }
            dp[i]%=mod;
           }
        }
        return (int)dp[0];
    }
};
