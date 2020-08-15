#include<iostream>
#include<string.h>

using namespace std;

constexpr auto INF = 1e9;
int n, m;
int arr[102][102];


int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			arr[i][j] = INF;

	int s, e, v;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &v);
		if(arr[s][e] > v)
			arr[s][e] = v;
	}

	/*for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (arr[i][j] != INF)
				printf("%d ", arr[i][j]);
			else
				printf("0 ");
		}
		printf("\n");
	}*/

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (i == j)
					continue;
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if(arr[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}