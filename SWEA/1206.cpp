#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
int N;
int arr[1002];
int ans = 0;

void find_ans() {
	int tmp;
	for (int i = 2; i < N - 2; i++) {
		tmp = 1e9;
		for (int j = i - 2; j < i + 3; j++) {
			if (i != j) {
				if (arr[i] <= arr[j])
					tmp = 0;
				else {
					tmp = min(tmp, arr[i] - arr[j]);
				}
			}
		}
		ans += tmp;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int t = 0; t < 10; t++) {
		ans = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		
		find_ans();
		printf("#%d %d\n", t + 1, ans);
	}


	return 0;

}