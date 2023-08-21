#include <stdio.h>

int binarySearch(int* nums, int target, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target)
        return binarySearch(nums, target, mid + 1, right);
    else
        return binarySearch(nums, target, left, mid - 1);
}

int search(int* nums, int numsSize, int target) {
    return binarySearch(nums, target, 0, numsSize - 1);
}

int main() {
    int arr[] = {1, 2, 4, 5, 6, 8, 10, 13}, target = 5;
    printf("%d", search(arr, 8, target));
}
