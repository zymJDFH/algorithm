//https://leetcode.cn/problems/distinct-subsequences-ii/

//一道很巧妙的dp题
// 记录以某字符为结尾的总数
// 遍历 纯新增=总数-s[i]的字符数
// s[i]的总字符数+=纯新增
// 总数+=纯新增
// 至于为什么每次减去s[i]的字符数就是纯新增
// 因为以s[i]字符结尾的子序列是由前面cnt[s[i]]个+s[i]可以构成它本身的子序列构成的
// 要注意减法的取模
class Solution {
public:
    const int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>cnt(26,0);
        
        int add=0;
        long ans=1;
        for(int i=0;i<n;i++){
            add=(ans-cnt[s[i]-'a']+mod)%mod;
            cnt[s[i]-'a']=(cnt[s[i]-'a']+add)%mod;
            ans=(ans+add)%mod;
        }
        ans%=mod;
        return (ans-1+mod)%mod;
    }
};