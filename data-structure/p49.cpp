#include<iostream>

using namespace std;

int main() {

	int *p;
	p = (int*)malloc(4*sizeof(int));

	if (p == NULL)
		printf("�޸� �Ҵ� ����\n");
	else
	{
		for (int i = 0; i < 4; i++) {
			*(p + i) = i;
		}
		for (int i = 0; i < 4; i++) {
			printf("%2d", *(p+i));
		}
	}
	free(p);

	return 0;
}