#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	int max;

	printf("3개의 정수 입력:");
	scanf("%d %d %d", &a, &b, &c);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;

	printf("제일 큰 정수: %d\n", max);

	return 0;
}