#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sortJobs(int* difficulty, int* profit, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (difficulty[j] > difficulty[j + 1]) {
				swap(&difficulty[j], &difficulty[j + 1]);
				swap(&profit[j], &profit[j + 1]);
			}
		}
	}
}
void sortWorkers(int* workers, int m) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < m - i - 1; j++) {
			if (workers[j] > workers[j + 1]) {
				swap(&workers[j], &workers[j + 1]);
			}
		}
	}
}
int maxProfit(int* difficulty, int* profit, int n, int* workers, int m) {
	sortJobs(difficulty, profit, n);
	sortWorkers(workers, m);
	int totalProfit = 0;
	int maxProfit = 0;
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j < n && workers[i] >= difficulty[j]) {
			if (profit[j] > maxProfit) {
				maxProfit = profit[j];
			}
			j++;
		}
		totalProfit += maxProfit;
	}
	return totalProfit;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int difficulty[n], profit[n], workers[m];
	for (int i = 0; i < n; i++) {
		scanf("%d", &difficulty[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &profit[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &workers[i]);
	}
	int result = maxProfit(difficulty, profit, n, workers, m);
	printf("%d\n", result);
	return 0;
}

