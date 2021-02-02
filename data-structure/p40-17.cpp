#include<iostream>

using namespace std;

void Spira(int a) {
	for (int i = 1; i <= a; i++) {
		for (int j = 0; j < a - i; j++)
			printf(" ");
		for (int j = 0; j < i*2 -1; j++)
			printf("*");

		printf("\n");
	}
}

int main() {

	int a;

	printf("input num: ");
	scanf("%d", &a);

	Spira(a);



	return 0;
}