#include <limits.h>
#include <stdio.h>

int max2(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max2(max2(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    int left = maxSubArraySum(arr, l, m);
    int right = maxSubArraySum(arr, m + 1, r);
    int crossing = maxCrossingSum(arr, l, m, r);
    return max(left, right, crossing);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
