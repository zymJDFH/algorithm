class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;
        int n = t.size();
        vector<int>ans(n, 0);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && t[i] > t[s.top()]) {
                int u = s.top();
                s.pop();
                ans[u] = i - u;
            }
            s.push(i);
        }
        return ans;
    }
};