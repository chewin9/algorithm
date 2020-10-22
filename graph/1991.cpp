#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct Node {
	char node;
	int left_node;
	int right_node;
}Node;
int N;
Node no[28];

void postorder(int root) {
	if (no[root].left_node != -1)
		postorder(no[root].left_node);
	if (no[root].right_node != -1)
		postorder(no[root].right_node);
	printf("%c", no[root].node);
}
void inorder(int root) {
	if (no[root].left_node != -1)
		inorder(no[root].left_node);
	printf("%c", no[root].node);
	if (no[root].right_node != -1)
		inorder(no[root].right_node);
}
void preorder(int root) {
	printf("%c", no[root].node);

	if (no[root].left_node != -1)
		preorder(no[root].left_node);
	if (no[root].right_node != -1)
		preorder(no[root].right_node);
}
int main() {
	scanf("%d", &N);

	char p, l, r;
	int tmp;
	fflush(stdin);
	for (int i = 0; i < N; i++) {
		//scanf("%c %c %c", &p, &l, &r);
		cin >> p;
		cin >> l;
		cin >> r;
		tmp = p - 'A';
		no[tmp].node = p;
		if (l == '.')
			no[tmp].left_node = -1;
		else
			no[tmp].left_node = l - 'A';

		if (r == '.')
			no[tmp].right_node = -1;
		else
			no[tmp].right_node = r - 'A';
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");


	return 0;
}