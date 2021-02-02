#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

int K, ans;
vector<int> arr;
stack<int> st;

int main() {
	scanf("%d", &K);

	int cost;
	for (int i = 0; i < K; i++) {
		scanf("%d", &cost);
		if (cost == 0) {
			if(st.empty() == false)
				st.pop();
		}
		else
			st.push(cost);
	}

	while (!st.empty()) {
		cost = st.top();
		ans += cost;
		st.pop();
	}
	printf("%d\n", ans);
	return 0;
}