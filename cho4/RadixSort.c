#include <stdio.h>
#include <stdlib.h>

void RadixSort(int a[], int n) {
    int digit_cnt[10] = { 0 }; // 10칸이 모두 0으로 채워짐
    int* b = (int*)malloc(sizeof(int) * n);
    int digit = 1, max = a[0], i;

    // 배열에서 최대값 찾기
    for (i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }
    // 기수 정렬 수행
    while (digit <= max) {
        for (i = 0; i < n; i++) {
            digit_cnt[a[i] / digit % 10]++;
        }
        for (i = 1; i < 10; i++) {
            digit_cnt[i] += digit_cnt[i - 1];
        }
        // 현재 자릿수 기준으로 정렬된 값을 임시 배열에 저장
        for (i = n - 1; i >= 0; i--) {
            b[--digit_cnt[a[i] / digit % 10]] = a[i];
        }
        for (i = 0; i < n; i++) {
            a[i] = b[i];
        }
        // 다음 자릿수를 위해 카운트 배열 초기화
        for (i = 0; i < 10; i++) {
            digit_cnt[i] = 0;
        }
        for (i = 0; i < n; i++) {
            printf("%6d", a[i]);
        }
        printf("\n");
        // 다음 자릿수로 이동
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
