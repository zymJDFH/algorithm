//优先队列
class Solution {
public:

        int nthUglyNumber(int n) {
        int a[3]={2,3,5};
        vector<int>dp(2000);
        dp[1]=1;
        priority_queue<long long,vector<long long>,greater<long long>>q;
       
        for(int i=2;i<=n;i++){
            for(int j=0;j<3;j++){
                q.push((long long)dp[i-1]*a[j]);
            }
            while(q.top()==dp[i-1]){
                q.pop();     
            }
            dp[i]=q.top();
        }
        return dp[n];
    }
};

//三指针
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[1]=1;
        int p2=1,p3=1,p5=1;
        for(int i=2,a,b,c,cur;i<=n;i++){
            a=dp[p2]*2;
            b=dp[p3]*3;
            c=dp[p5]*5;
            cur=min(a,min(b,c));
            if(a==cur)p2++;
            if(b==cur)p3++;
            if(c==cur)p5++;
            dp[i]=cur;  
        }
        return dp[n];
    }
};
