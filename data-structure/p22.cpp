#include<iostream>

using namespace std;

int main() {

	int a;

	printf("input num:");
	scanf("%d", &a);

	if (a > 0)
		printf("���\n");
	else if (a < 0)
		printf("����\n");
	else
		printf("0\n");



	return 0;
}