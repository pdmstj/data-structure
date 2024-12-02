#include <stdio.h>

int interpolationSearch(int a[], int n, int key) {
	int left = 0, right = n - 1, mid;

	while (left <= right && key >= a[left] && key <= a[right]) {
		// 배열이 정렬되어 있어야 하며, 나눗셈의 분모가 0이 되지 않도록 방지
		if (left == right) {
			if (a[left] == key) return left;
			return -1;
		}

		// mid 계산
		mid = left + ((key - a[left]) * (right - left)) / (a[right] - a[left]);

		// key 값을 찾은 경우
		if (a[mid] == key) {
			return mid;
		}

		// key 값이 더 크면 오른쪽 부분 탐색
		if (a[mid] < key) {
			left = mid + 1;
		}
		// key 값이 더 작으면 왼쪽 부분 탐색
		else {
			right = mid - 1;
		}
	}

	return -1;
}

int main(void) {

	int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
	int n = sizeof(a) / sizeof(int);

	int index, key;

	printf("찾을 값 : ");
	scanf_s("%d", &key);

	index = interpolationSearch(a, n, key);
	if (index >= 0)
		printf("\n%d을(를) %d 위치에서 찾음! \n", key, index);
	else
		printf("\n찾고자 하는 값이 없음! \n");

	return 0;
}
