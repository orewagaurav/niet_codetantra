#include <stdio.h>
#include <stdlib.h>

void findSubsets(int arr[], int n, int target, int index, int curr_sum, int curr_subset[], int subset_size, int** subsets, int* subset_count) {
    if (curr_sum == target) {
        subsets[*subset_count] = (int*)malloc((subset_size + 1) * sizeof(int));
        for (int i = 0; i < subset_size; i++) {
            subsets[*subset_count][i] = curr_subset[i];
        }
        subsets[*subset_count][subset_size] = -1; 
        (*subset_count)++;
        return;
    }
    if (index == n || curr_sum > target) return;

    curr_subset[subset_size] = arr[index];
    findSubsets(arr, n, target, index + 1, curr_sum + arr[index], curr_subset, subset_size + 1, subsets, subset_count);

    findSubsets(arr, n, target, index + 1, curr_sum, curr_subset, subset_size, subsets, subset_count);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);

    int curr_subset[n];
    int* subsets[100]; 
    int subset_count = 0;

    findSubsets(arr, n, target, 0, 0, curr_subset, 0, subsets, &subset_count);

    if (subset_count == 0) {
        printf("-1\n");
    } else {
        for (int i = subset_count - 1; i >= 0; i--) {
            int j = 0;
            while (subsets[i][j] != -1) {
                printf("%d", subsets[i][j]);
                printf(" ");
                j++;
            }
            printf("\n");
            free(subsets[i]); 
        }
    }
    return 0;
}







