#include <stdio.h>
#include <stdlib.h>

void RadixSort(int a[], int n) {
    int digit_cnt[10] = { 0 }; // 10ĭ�� ��� 0���� ä����
    int* b = (int*)malloc(sizeof(int) * n);
    int digit = 1, max = a[0], i;

    // �迭���� �ִ밪 ã��
    for (i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }
    // ��� ���� ����
    while (digit <= max) {
        for (i = 0; i < n; i++) {
            digit_cnt[a[i] / digit % 10]++;
        }
        for (i = 1; i < 10; i++) {
            digit_cnt[i] += digit_cnt[i - 1];
        }
        // ���� �ڸ��� �������� ���ĵ� ���� �ӽ� �迭�� ����
        for (i = n - 1; i >= 0; i--) {
            b[--digit_cnt[a[i] / digit % 10]] = a[i];
        }
        for (i = 0; i < n; i++) {
            a[i] = b[i];
        }
        // ���� �ڸ����� ���� ī��Ʈ �迭 �ʱ�ȭ
        for (i = 0; i < 10; i++) {
            digit_cnt[i] = 0;
        }
        for (i = 0; i < n; i++) {
            printf("%6d", a[i]);
        }
        printf("\n");
        // ���� �ڸ����� �̵�
        digit *= 10;
    }

    free(b);
}

int main(void) {
    int a[] = { 10, 512, 3, 29, 318, 50, 7215, 1283, 99, 148, 303, 717 };
    int n = sizeof(a) / sizeof(int);

    RadixSort(a, n);

    return 0;
}
