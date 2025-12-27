#include <stdlib.h>
// @leet start
double findMedianSortedArrays(int* nums1, int n, int* nums2, int m) {
  int* nums = malloc(sizeof(int)*(n+m));
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n && j < m) {
    if (nums1[i] <= nums2[j]) {
      nums[k] = nums1[i];
      i++;
    } else {
      nums[k] = nums2[j];
      j++;
    }
    k++;
  }
  while (i < n) {
    nums[k] = nums1[i];
    i++;
    k++;
  }
  while (j < m) {
    nums[k] = nums2[j];
    j++;
    k++;
  }
  unsigned int median = (n+m)/2;
  if ((n+m) % 2 == 0) {
    return (double) (nums[median]+nums[median-1])/2.;
  } else {
    return (double) nums[median];
  }
}
// @leet end
