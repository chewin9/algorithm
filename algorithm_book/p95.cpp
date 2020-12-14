/*
N일 동안의 무게
M일 동안의 평균 무게
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	vector<int> arr;
	vector<double> answer;

	for (int i = 1; i < 13; i++)
		arr.push_back(i);

	int N, M;
	N = arr.size();
	M = 3;
	double sum;
	printf("case1=================\n");
	// case 1
	// 시간 복잡도 = (N-M+1) * M
	for (int i = 0; i < N - M+1; i++) {
		sum = 0;
		for (int j = 0; j < M; j++) {
			sum += arr.at(i + j);
		}
		answer.push_back(sum / M);
	}
	for (int i = 0; i < answer.size(); i++)
		printf("%.3f\n", answer.at(i));
	answer.clear();

	printf("case2=================\n");
	// case 2
	// 시간 복잡도 = N
	sum = 0;
	for (int i = 0; i < M - 1; i++) {
		sum += arr.at(i);
	}
	for (int i = M - 1; i < N; i++) {
		sum += arr.at(i);
		answer.push_back(sum / M);
		sum -= arr.at(i - M+1);
	}
	for (int i = 0; i < answer.size(); i++)
		printf("%.3f\n", answer.at(i));

	return 0;
}