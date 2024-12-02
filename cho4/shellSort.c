#include <stdio.h>

void shellSort(int a[], int n) {
    int i, j, key, t = n / 2;

    for (t = n / 2; t >= 1; t /= 2) {
        for (i = t; i < n; i++) {
            key = a[i];
            for (j = i - t; j >= 0; j-=t) {
                if (a[j] <= key) break;
                else a[j + t] = a[j];
            }
            a[j + t] = key;

        }
    }
}

int main(void) {
    int a[] = {17, 8, 20, 11, 5, 12, 15, 7, 35, 21, 48, 30, 25};
    int n = sizeof(a) / sizeof(int);

    shellSort(a, n);  // �Լ� �̸� ����

    for (int i = 0; i < n; i++)
        printf("%5d", a[i]);

    return 0;
}

