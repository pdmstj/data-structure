#include <stdio.h>
#define SIZE 8

typedef enum { false, true } bool;

int stack[SIZE];
int top = -1;

void push(int index) {
	stack[++top] = index;
}

int pop(void) {
	if (top == -1) return -1;  // '='을 '=='로 수정
	return stack[top--];
}

void DepthFirstSearch(char V[], bool G[][SIZE]) {
	int i, j;
	char startVertex;
	bool searchOK[SIZE] = { false };
	printf("출발 정점: ");
	scanf_s("%c", &startVertex, 1);

	for (i = 0; i < SIZE; i++) {
		if (V[i] == startVertex) break;
	}

	if (i == SIZE) {
		printf("입력한 정점이 존재하지 않습니다.\n");
		return;
	}

	printf("깊이우선탐색 : %c", V[i]);  // "%C"를 "%c"로 변경
	searchOK[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == false) {
				printf(" -> %c", V[j]);
				push(i);
				i = j;
				searchOK[j] = true;
				break;
			}
		}
		if (j == SIZE) i = pop();  // 연결된 정점이 없으면 pop
	} while (i >= 0);
}

int main(void) {
	char V[] = { 'A','B','C','D','E','F','G','H' };
	bool G[SIZE][SIZE] = {
		{0, 1, 1, 0, 0, 0, 0 ,0},
		{1, 0, 0, 1, 1, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 1},
		{0, 0, 0, 1, 1, 1, 1, 0}
	};

	DepthFirstSearch(V, G);

	return 0;
}
