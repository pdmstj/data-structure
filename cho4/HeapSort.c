#include <stdio.h>
#include <limits.h>

void HeapSort(int a[], int n) {
	int i, parent, child, value, size = n;

	//최대힙 구성
	for (i = n / 2; i >= 1; i--) {
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		}
		a[parent] = value;
	}

	printf("최대힙: ");
	for (i = 1; i <= n; i++) printf("%4d", a[i]);
	printf("\n\n");

	//힙 정렬(최대값 이동 및 힙 재구성)
	while (n > 1) {
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n) {
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) {
				a[parent] = a[child];
				parent = child;
			}
			else break;
		}
		a[parent] = value;

		printf("단계%3d:", size - n);
		for (i = 1; i < size; i++)
			printf("%5d", a[i]);
		printf("\n");
	}
}

int main(void) {
	int a[] = { 21,12,9,17,3,1,20,15,25,11 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬전: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	HeapSort(a, n - 1);

	printf("\n정렬후: ");
	for (i = 1; i < n; i++)	printf("%4d", a[i]);
	printf("\n\n");

	return 0;
}