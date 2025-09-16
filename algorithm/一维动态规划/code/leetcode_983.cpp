//https://leetcode.cn/problems/minimum-cost-for-tickets/

//递归
class Solution {
public:
    int duration[3]={1,7,30};
    int mincost(vector<int>& days, vector<int>& costs,int i){
        int n=days.size();
        if(i>=n){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=0,j=i;k<3;k++){
            while(j<n&&duration[k]+days[i]>days[j]){
                j++;
            }
            ans=min(ans,(costs[k]+mincost(days,costs,j)));
        }
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincost(days,costs,0);
    }
};

//记忆化搜索
class Solution {
public:
    int duration[3]={1,7,30};
    int dp[400];
    int mincost(vector<int>& days, vector<int>& costs,int i){
        int n=days.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int k=0,j=i;k<3;k++){
            while(j<n&&duration[k]+days[i]>days[j]){
                j++;
            }
            ans=min(ans,(costs[k]+mincost(days,costs,j)));
            dp[i]=ans;
        }
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return mincost(days,costs,0);
    }
};

//动态规划
class Solution {
public:
    int duration[3]={1,7,30};
    int dp[400];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       memset(dp,0x3f,sizeof(dp));
       int n=days.size();
       dp[n]=0;
       for(int i=n-1;i>=0;i--){
        for(int k=0;k<3;k++){
            int j=i;
            while(j<n&&duration[k]+days[i]>days[j]){
                    j++;
                }
                dp[i]=min(dp[i],costs[k]+dp[j]);

        }
       }
       return dp[0]; 
    }
};

