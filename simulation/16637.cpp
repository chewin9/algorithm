#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N, ans = -1e9;
char str[20];

int calu(int a, int b, char oper) {
	int tmp = a;
	switch (oper) {
	case '+':
		tmp += b;
		break;
	case '*':
		tmp *= b;
		break;
	case '-':
		tmp -= b;
		break;
	}
	return tmp;
}

void dfs(int pos, int val) {
	if (pos > N - 1) {
		ans = max(val, ans);
		return;
	}

	char oper;
	if (pos == 0) {
		oper = '+';
	}
	else {
		oper = str[pos - 1];
	}

	if (pos + 2 < N) {
		int tmp = calu(str[pos] - '0', str[pos + 2] - '0', str[pos + 1]);
		dfs(pos + 4, calu(val, tmp, oper));
	}
	dfs(pos + 2, calu(val, str[pos]-'0', oper));
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %1c", &str[i]);
	}

	dfs(0, 0);

	printf("%d\n", ans);

	return 0;
}