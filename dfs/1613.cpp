#include<iostream>
#include<vector>

using namespace std;

#define INF 1e9
int n, k, s;
int arr[402][402];


int main() {
	scanf("%d %d", &n, &k);

	int a, b;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (arr[i][j] != 1)
				arr[i][j] = INF;
		}
	}
	
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (arr[i][j] == 1)
				arr[j][i] = -1;
		}
	}

	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%d %d", &a, &b);

		if (arr[a][b] == 1)
			printf("-1\n");
		else if (arr[a][b] == -1)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;

}