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

	printf("3���� ���� �Է�:");
	scanf("%d %d %d", &a, &b, &c);

	printf("�ִ�: %d\n", Max(a, b, c));


	return 0;
}