#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	int max;

	printf("3���� ���� �Է�:");
	scanf("%d %d %d", &a, &b, &c);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;

	printf("���� ū ����: %d\n", max);

	return 0;
}