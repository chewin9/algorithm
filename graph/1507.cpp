#include<iostream>

using namespace std;

constexpr auto INF = 1e9;;
int N;
int arr[22][22];
int copy_arr[22][22];
int ans;

void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void copy() {
	for(int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			copy_arr[i][j] = arr[i][j];
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);

	copy();

	for (int k = 1; k < N + 1; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (copy_arr[i][j] == copy_arr[i][k] + copy_arr[k][j] && i != j && j != k && k != i)
					copy_arr[i][j] = INF;
			}
		}
	}
	//show();

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (copy_arr[i][j] != INF) {
				ans += copy_arr[i][j];
			}
		}
	}
	for (int k = 1; k < N + 1; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (copy_arr[i][j] > copy_arr[i][k] + copy_arr[k][j])
					copy_arr[i][j] = copy_arr[i][k] + copy_arr[k][j];
			}
		}
	}
	
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] != copy_arr[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", ans/2);
	return 0;
}