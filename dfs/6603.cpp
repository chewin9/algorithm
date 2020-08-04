#include<iostream>
#include<string.h>
using namespace std;

int k;
int arr[15];
bool visit[50];

void showLotto() {
	for (int i = 0; i < k; i++) {
		if (visit[i] == true)
			printf("%d ", arr[i]);
	}
	printf("\n");
}

void dfs(int pos, int cnt) {
	visit[pos] = true;

	if (cnt == 6) {
		showLotto();
		visit[pos] = false;
		return;
	}
	for (int i = pos+1; i < k; i++) {
		dfs(i, cnt + 1);
	}
	visit[pos] = false;
}


int main() {
	do {
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));

		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < k - 5; i++) {
			dfs(i,1);
		}
		printf("\n");
	} while (k != 0);



	return 0;
}