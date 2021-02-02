#include<iostream>

using namespace std;

int main() {

	int a;

	printf("input num:");
	scanf("%d", &a);

	if (a > 0)
		printf("양수\n");
	else if (a < 0)
		printf("음수\n");
	else
		printf("0\n");



	return 0;
}