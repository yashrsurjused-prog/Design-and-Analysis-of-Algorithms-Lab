#include <stdio.h>

#define MAX_ELEMENTS 20
#define MAX_SUBSETS 1000

int subsets[MAX_SUBSETS][MAX_ELEMENTS];
int subset_sizes[MAX_SUBSETS];
int subset_count = 0;
int current_subset[MAX_ELEMENTS];

void findSubsets(int arr[], int n, int index, int current_sum, int target_sum, int current_size) {
    if (current_sum == target_sum) {
        for (int i = 0; i < current_size; i++) {
            subsets[subset_count][i] = current_subset[i];
        }
        subset_sizes[subset_count] = current_size;
        subset_count++;
        return;
    }

    if (index >= n || current_sum > target_sum) {
        return;
    }

    // Include current element
    current_subset[current_size] = arr[index];
    findSubsets(arr, n, index + 1, current_sum + arr[index], target_sum, current_size + 1);

    // Exclude current element
    findSubsets(arr, n, index + 1, current_sum, target_sum, current_size);
}

int main() {
    int n, sum;
    if (scanf("%d", &n) != 1) return 0;

    int arr[MAX_ELEMENTS];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &sum);

    findSubsets(arr, n, 0, 0, sum, 0);

    if (subset_count == 0) {
        printf("-1\n");
    } else {
        // Output in reverse order of discovery without trailing spaces
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < subset_sizes[i]; j++) {
                printf("%d", subsets[i][j]);
                if (j < subset_sizes[i] - 1) {
                    printf(" ");
                }
            }
            printf(" \n");
        }
    }

    return 0;
}
