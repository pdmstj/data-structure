#include <stdio.h>

#define R 3 // 고정된 R의 크기
int b[R] = { 0 }; // 선택된 요소를 저장할 배열
int cnt = 0;    // 순열 개수를 세는 변수

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
            exchange(a + r, a + i); // 요소 교환
            b[r] = a[r];           // 선택된 요소 저장
            Permutation(a, n, r + 1); // 재귀 호출
            exchange(a + r, a + i); // 원래 상태로 복원
        }
    }
}

int main(void) {
    int a[] = { 1, 2, 3, 4, 5 }; // 입력 배열
    int n = sizeof(a) / sizeof(int); // 배열 크기 계산
    Permutation(a, n, 0); // 순열 생성 시작
    printf("순열 개수 : %d\n", cnt);
    return 0;
}
