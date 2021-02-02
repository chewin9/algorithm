#include<iostream>

using namespace std;

int main() {

	int a;

	printf("input num: ");
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}



	return 0;
}