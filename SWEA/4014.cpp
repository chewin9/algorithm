#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>


using namespace std;

int T, X, N;
int map[22][22];
int arr[22];
int ans = 0;
bool check[22];
bool solve() {
	for (int i = 2; i < N + 1; i++) {
		if (arr[i] != arr[i - 1]){// && abs(arr[i]-arr[i-1]) == 1) {				//설치해야하고
			int tmp = arr[i] - arr[i - 1];
			if (tmp > 1 || tmp < -1)
				return false;
			
			if (arr[i] > arr[i - 1]) {			// 이전 땅이 낮은 경우
				int cnt = 1;
				check[i-1] = true;
				for (int j = i - 1; j > 1; j--) {
					if (arr[j] == arr[j - 1] && check[j - 1] == false) {
						check[j - 1] = true;
						cnt++;
					}
					else
						return false;
					if (cnt == X)
						break;
				}
				if (cnt != X)
					return false;
			}

			else {
				int cnt = 1;
				check[i] = true;
				for (int j = i; j < N + 1; j++) {
					if (arr[j] == arr[j + 1] && check[j + 1] == false) {
						cnt++;
						check[j + 1] = true;
					}
					else
						return false;
					if (cnt == X)
						break;
				}
				if (cnt != X)
					return false;
			}
		}
	}
	return true;

}
int main() {
	
	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		memset(map, 0,sizeof(map));
		ans = 0;
		scanf("%d %d", &N, &X);

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 1; i < N + 1; i++) {
			memset(arr, 0, sizeof(arr));
			memset(check, false, sizeof(check));
			for (int j = 1; j < N + 1; j++) {
				arr[j] = map[i][j];
			}
			if (solve()) {
				//printf("1. %d \n", i);
				ans++;
			}
		}
		for (int j = 1; j < N + 1; j++) {
			memset(arr, 0, sizeof(arr));
			memset(check, false, sizeof(check));
			for (int i = 1; i < N + 1; i++) {
				arr[i] = map[i][j];
			}
			if (solve()) {
				//printf("2. %d\n", j);
				ans++;
			}
		}

		printf("#%d %d\n", t, ans);
	}




	return 0;
}