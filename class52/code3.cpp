class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s;
        int n = arr.size();
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[i] <= arr[s.top()]) {
                int u = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top();
                ans = (ans + (long long)(u - l) * (i - u) * arr[u]) % mod;
            }
            s.push(i);
        }
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            int l = s.empty() ? -1 : s.top();
            ans = (ans + (long long)(u - l) * (n - u) * arr[u]) % mod;
        }
        return (int)ans;
    }
};