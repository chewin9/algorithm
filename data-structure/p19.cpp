#include<iostream>

using namespace std;

int Max4(int a, int b, int c, int d) {
	int max = a;

	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;

	return max;
}
int Min3(int a, int b, int c) {
	int min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;

	return min;
}

int Min4(int a, int b, int c, int d) {
	int min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;

	return min;
}
int main() {

	int a, b, c, d;

	printf("4���� ���� �Է�:");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("�ִ�: %d\n", Max4(a, b, c, d));

	
	printf("3���� ���� �Է�:");
	scanf("%d %d %d", &a, &b, &c);

	printf("�ּڰ�: %d\n", Min3(a, b, c));


	printf("4���� ���� �Է�:");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("�ּڰ�: %d\n", Min4(a, b, c, d));

	return 0;



}