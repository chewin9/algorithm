#include<iostream>

using namespace std;

int Mid3(int a, int b, int c) {
	if (a >= b) {
		if (b >= c) {
			return b;
		}
		else if (a <= c)
			return a;
		else
			return c;
	}
	else if (a >= c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}

int main() {

	int a, b, c;

	printf("3���� ���� �Է�:");
	scanf("%d %d %d", &a, &b, &c);

	printf("�߰���: %d\n", Mid3(a, b, c));


	return 0;
}