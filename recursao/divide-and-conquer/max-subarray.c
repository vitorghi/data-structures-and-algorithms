#include <limits.h>
#include <stdio.h>

int max2(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max2(max2(a, b), c); }

// Find the maximum possible sum in arr[] auch that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h) {
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) return arr[l];

    int m = (l + h) / 2;

    int left = maxSubArraySum(arr, l, m);
    int right = maxSubArraySum(arr, m + 1, h);
    int crossing = maxCrossingSum(arr, l, m, h);
    return max(left, right, crossing);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}

int maxSubArraySumX(int arr[], int l, int h) {
    if (l == h) return arr[l];

    int m = (l + h) / 2;

    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}