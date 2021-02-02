#include<iostream>

using namespace std;

int Max(int a, int b, int c) {
	int max = a;

	if (b > max)
		max = b;
	if (c > max)
		max = c;

	return max;
}

int main() {

	int a, b, c;

	printf("3개의 정수 입력:");
	scanf("%d %d %d", &a, &b, &c);

	printf("최댓값: %d\n", Max(a, b, c));


	return 0;
}