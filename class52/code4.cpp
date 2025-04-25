class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int>s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                int cur = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top();
                ans = max(ans, (i - l - 1) * heights[cur]);
            }
            s.push(i);
        }
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            int l = s.empty() ? -1 : s.top();
            ans = max(ans, (n - l - 1) * heights[cur]);
        }
        return ans;
    }
};