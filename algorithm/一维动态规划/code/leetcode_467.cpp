class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int ans=0;
        vector<int>cnt(26,0);
        vector<int>dp(26,0);
        dp[s[0]-'a']=1;
        cnt[s[0]-'a']=1;
        for(int i=1;i<s.size();i++){
            if((s[i]-'a')==(s[i-1]-'a'+1)%26){
                cnt[s[i]-'a']=cnt[s[i-1]-'a']+1;
            }else{
                cnt[s[i]-'a']=1;
            }
            dp[s[i]-'a']=max(dp[s[i]-'a'],cnt[s[i]-'a']);
        }
        for(int i=0;i<26;i++){
            ans+=dp[i];
        }
        return ans;
    }
};

//优化版
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int ans=0;
        vector<int>dp(26,0);
        dp[s[0]-'a']=1;
        int k=1;
        for(int i=1;i<s.size();i++){
            if((s[i]-'a')==(s[i-1]-'a'+1)%26){
                k++;
            }else{
               k=1;
            }
            dp[s[i]-'a']=max(dp[s[i]-'a'],k);
        }
        for(int i=0;i<26;i++){
            ans+=dp[i];
        }
        return ans;
    }
};