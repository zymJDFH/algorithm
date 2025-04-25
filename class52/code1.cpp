#include<iostream>
#include<stack>
using namespace std;
int a[1000005];
int ans[1000005][2];
int n, r;
stack<int>s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (!s.empty() && a[i] <= a[s.top()]) {
			int u = s.top();
			ans[u][1] = i;
			s.pop();
			ans[u][0] = s.empty() ? -1 : s.top();
		}
		s.push(i);
	}
	while (!s.empty()) {
		int u = s.top();
		ans[u][1] = -1;
		s.pop();
		ans[u][0] = s.empty() ? -1 : s.top();
	}
	for (int i = n - 2; i >= 0; i--) {
		if (a[ans[i][1]] == a[i]) {
			ans[i][1] = ans[ans[i][1]][1];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	//7 
	// 3 4 1 5 6 2 7

	return 0;
}