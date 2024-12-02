#include <stdio.h>

#define R 3 // ������ R�� ũ��
int b[R] = { 0 }; // ���õ� ��Ҹ� ������ �迭
int cnt = 0;    // ���� ������ ���� ����

void PrintPer() {
    for (int i = 0; i < R; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    cnt++;
}

void exchange(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Permutation(int a[], int n, int r) {
    if (r >= R) {
        PrintPer();
    }
    else {
        for (int i = r; i < n; i++) {
            exchange(a + r, a + i); // ��� ��ȯ
            b[r] = a[r];           // ���õ� ��� ����
            Permutation(a, n, r + 1); // ��� ȣ��
            exchange(a + r, a + i); // ���� ���·� ����
        }
    }
}

int main(void) {
    int a[] = { 1, 2, 3, 4, 5 }; // �Է� �迭
    int n = sizeof(a) / sizeof(int); // �迭 ũ�� ���
    Permutation(a, n, 0); // ���� ���� ����
    printf("���� ���� : %d\n", cnt);
    return 0;
}
