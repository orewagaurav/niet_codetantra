#include <stdio.h>
void merge(int nums1[], int m, int nums2[], int n) {
	int mergedIndex = m + n - 1;
	int i = m - 1;
	int j = n - 1;

	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums2[j]) {
			nums1[mergedIndex] = nums1[i];
			i--;
		} else {
			nums1[mergedIndex] = nums2[j];
			j--;
		}
		mergedIndex--;
	}
	while (j >= 0) {
		nums1[mergedIndex] = nums2[j];
		j--;
		mergedIndex--;
	}
}
int main() {
	int nums1[200], m;
	int nums1Size = 0;
	while (scanf("%d", &nums1[nums1Size]) == 1) {
		nums1Size++;
		if (getchar() == '\n') break;
	}
	scanf("%d", &m);
	int nums2[200], n;
	int nums2Size = 0;
	while (scanf("%d", &nums2[nums2Size]) == 1) {
		nums2Size++;
		if (getchar() == '\n') break;
	}
	scanf("%d", &n);
	merge(nums1, m, nums2, n);
	printf("[");
	for (int i = 0; i < m + n; i++) {
		printf("%d", nums1[i]);
		if (i != m + n - 1) printf(", ");
	}
	printf("]\n");
	return 0;
}