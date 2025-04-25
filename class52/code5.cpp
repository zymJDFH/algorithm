class Solution {
    int st[205];
    int h[201];
public:
    int largestRectangleArea(int m) {
        int r = 0;
        int ans = 0, cur, left;
        for (int i = 0; i < m; i++) {
            while (r > 0 && h[i] <= h[st[r - 1]]) {
                cur = st[--r];
                left = r == 0 ? -1 : st[r - 1];
                ans = max(ans, (i - 1 - left) * h[cur]);
            }
            st[r++] = i;
        }
        while (r > 0) {
            cur = st[--r];
            left = r == 0 ? -1 : st[r - 1];
            ans = max(ans, (m - 1 - left) * h[cur]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                h[j] = matrix[i][j] == '0' ? 0 : h[j] + 1;
            }
            ans = max(ans, largestRectangleArea(m));
        }
        return ans;
    }
};