#include <stdio.h>

int interpolationSearch(int a[], int n, int key) {
	int left = 0, right = n - 1, mid;

	while (left <= right && key >= a[left] && key <= a[right]) {
		// �迭�� ���ĵǾ� �־�� �ϸ�, �������� �и� 0�� ���� �ʵ��� ����
		if (left == right) {
			if (a[left] == key) return left;
			return -1;
		}

		// mid ���
		mid = left + ((key - a[left]) * (right - left)) / (a[right] - a[left]);

		// key ���� ã�� ���
		if (a[mid] == key) {
			return mid;
		}

		// key ���� �� ũ�� ������ �κ� Ž��
		if (a[mid] < key) {
			left = mid + 1;
		}
		// key ���� �� ������ ���� �κ� Ž��
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

	printf("ã�� �� : ");
	scanf_s("%d", &key);

	index = interpolationSearch(a, n, key);
	if (index >= 0)
		printf("\n%d��(��) %d ��ġ���� ã��! \n", key, index);
	else
		printf("\nã���� �ϴ� ���� ����! \n");

	return 0;
}
