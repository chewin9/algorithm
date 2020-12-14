/*
배열에서 연속된 합중 가장 큰 값을 찾는 문제
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;
vector<int> arr;
int M;
int fastMaxSum(vector<int> &arr, int low, int high) {
	//printf("{%d %d}\n", low, high);
	if (low == high)
		return arr[low];

	int mid = (low + high) / 2;

	int left, right, sum;
	sum = 0;
	left = right = -1e9;

	for (int i = low; i < mid + 1; i++) {
		sum += arr[i];
		left = max(left, sum);
	}
	sum = 0;
	for (int i = mid + 1; i < high + 1; i++) {
		sum += arr[i];
		right = max(right, sum);
	}

	int single = max(fastMaxSum(arr, low, mid),
		fastMaxSum(arr, mid + 1, high));

	return max(left + right, single);
}

int main() {
	printf("input size:");
	scanf("%d", &M);

	int num;
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		arr.push_back(num);
	}

	int answer = 0;

	answer = fastMaxSum(arr, 0, M - 1);

	printf("%d\n", answer);
	return 0;

}