#include<iostream>

using namespace std;

void Tri_1(int a) {
	printf("Tri_1\n");
	for (int i = 1; i <= a; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void Tri_2(int a) {
	printf("Tri_2\n");

	for (int i = a; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void Tri_3(int a) {
	printf("Tri_3\n");
	for (int i = a; i > 0; i--) {
		for (int j = a; j > i; j--)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}

void Tri_4(int a) {
	printf("Tri_4\n");

	for (int i = 1; i <= a; i++) {
		for (int j = a; j > i; j--)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}


int main() {

	int a;

	printf("input num: ");
	scanf("%d", &a);

	Tri_1(a);
	Tri_2(a);
	Tri_3(a);
	Tri_4(a);


	return 0;
}